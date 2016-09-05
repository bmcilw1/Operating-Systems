// Brian McIlwain
// Operating Systems
// A POSIX-compliant file copy.
// [16] Write a POSIX-compilant version of the cp command using C library function calls, 
// as described in Sec 2.3 (System Calls) [4], except mimic the behavior of cp (it should 
// be non-interactive, accept command-line arguments; replace the destination file by 
// default, etc.) [4]. In your version, include a progress bar which shows the file copy 
// progress in-line (you will need to use a trick that involves printing a carriage return)
// [4]. Call this copy.c. Indicate in comments all of the system calls which are triggered
// by calls to libc functions [4].

#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>

int main(int argc, char *argv[])
{
    // Input validation
    if (argc != 3) {
        fprintf(stderr, "Usage: source_file destination_file\n");
    }

    // Try to open source file
    FILE *source = fopen(argv[1], "rb");

    // If unable to open source file fail program
    if (source == 0) {
        fprintf(stderr, "Error: unable to open %s for reading.\n", argv[1]);
    }

    // Try to open destination file
    FILE *dest = fopen(argv[2], "wb");

    // If unable to open destination file fail program
    if (dest == 0) {
        fprintf(stderr, "Error: unable to open %s for writing.\n", argv[2]);
    }

    // Get source file size used for progress bar
    struct stat sourceSt;
    // stat: direct sys call
    stat(argv[1], &sourceSt);
    size_t sourceSize = sourceSt.st_size;

    // Buffer set up
    unsigned char buffer[1];
    size_t bytesRead = 0;
    size_t totalBytesRead = 0;

    // For progress bar
    float progress = 0.0;
    int prog = 0; 

    while ((bytesRead = fread(buffer, 1, sizeof(buffer), source)) > 0)
    {
        // Copy buffer chunk worth of file
        fwrite(buffer, sizeof(buffer), 1, dest);

        // Update meta data progress
        totalBytesRead += bytesRead;
        prog = 64 * ((totalBytesRead * 1.0) / (sourceSize * 1.0));

        // Update progress bar
        printf("[");
        for (int i = 0; i <= 64; ++i) {
            if (i <= prog) {
                printf("=");
            }
            else {
                printf(" ");
            }
        }
        printf("]\r");
    }

    printf("\n");

    fclose(dest);
    fclose(source);
    return 0;
}
