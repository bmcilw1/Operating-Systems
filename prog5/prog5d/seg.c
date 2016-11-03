// Brian McIlwain
// Segmentation fault trickery.
// Write a program to accept a PID as a command-line argument and send a SIGSEGV signal 
// to it to indicate a segmentation fault has occurred in that process (the process will 
// print out the classic "Segmentation fault" message on its own, as per the default 
// signal handler).

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

int main(int argc, char **argv) {
    if (argc != 2) {
        printf("Usage: %s pid\n", argv[0]);
        return 1;
    }

    int pid = atoi(argv[1]);

    printf("SIGSEGV pid: %i, %i\n", pid, kill(pid, SIGSEGV));

    return 0;
}
