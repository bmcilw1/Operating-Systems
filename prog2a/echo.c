// Brian McIlwian
// Op Sys HW2a
// Echo input using system calls.
// [16] Write a program which accepts a filename as a command-line argument, then 
// continuously reads a line from stdin and outputs the same line to stdout and to the 
// file (as indicated by the filename). You must use only system calls (no calls to printf
// or scanf are allowed). You can ensure that you use only system calls by verifying the 
// manual page section of the corresponding libc API function (e.g. man 2 open yields a 
// result, so open is a system call). Call this echo.c. Be sure to distinguish this echo 
// from the system command echo.

#include <string.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char *argv[])
{
    char msgBuff[256] = " \0"; 

    if (argc != 2) {
        strcpy(msgBuff, "Usage: program_name <filename>\n");

        write(STDOUT_FILENO, msgBuff, strlen(msgBuff));
        return 1;
    } 

    // Open file
    int fd = open(argv[1], O_CREAT|O_WRONLY);
    
    // Read the line from stdin
    while (read(STDIN_FILENO, msgBuff, strlen(msgBuff))) {
        // Echo it to stdout and the file specified
        write(fd, msgBuff, strlen(msgBuff));
        write(STDOUT_FILENO, msgBuff, strlen(msgBuff));
    }

    // Clean up
    close(fd);

    return 0;
}
