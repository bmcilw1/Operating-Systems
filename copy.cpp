// Brian McIlwain
// Operating Systems
// A POSIX-compliant file copy.
// [16] Write a POSIX-compilant version of the cp command using C library function calls,
// as described in Sec 2.3 (System Calls) [4], except mimic the behavior of cp 
// (it should be non-interactive, accept command-line arguments; replace the destination 
// file by default, etc.) [4]. In your version, include a progress bar which shows the file
// copy progress in-line (you will need to use a trick that involves printing a carriage return)[4]. 
// Call this copy.c. Indicate in comments all of the system calls which are triggered by calls to libc functions [4].

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char *argv[])
{
    
    return 0;
}
