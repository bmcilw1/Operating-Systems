// Brian McIlwian
// Op Sys HW2b
// Forking processes to calculate series and products.
// [16] Write a program which accepts an integer command-line argument (call it n`). The 
// program should then fork. The parent process shall calculate the product of numbers 1 
// to n, while the child process calculates the sum of numbers 1 to n (so they may 
// potentially be done concurrently on a multiprocessor system). The parent should wait 
// for the child to finish executing before printing its result. Call this series.c.

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <unistd.h>

int sum(int n);
int prod(int n);

int main(int argc, char *argv[])
{
    if (argc != 2) {
        printf("Usage: program_name <n`>\n");
        return 1;
    } 

    // Convert to int
    int n = atoi(argv[1]);

    // Fork
    int pid = fork();

    // Determine identity of process
    if (pid < 0) {
        printf("Error: forking\n");
    } else if (pid > 0) {
        printf("Product 1 to %i: %i\n", n, prod(n));
    } else {
        // Calculate the sum
        printf("Sum 1 to %i: %i\n", n, sum(n));
    }

    return 0;
}

int sum(int n) {
    if (n == 0)
        return 0;
    else if (n < 0)
        return n + sum(n+1);
    else
        return n + sum(n-1);
}

int prod(int n) {
    if (abs(n) <= 1)
        return n;
    else if (n < 0)
        return n * prod(n+1);
    else
        return n * prod(n-1);
}
