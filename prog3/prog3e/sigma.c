// Brian McIlwain
// Op Sys hw 3
// Sums and products
//  Using OpenMP, write a program which accepts integer start, stop, and step values 
//  (in that order) as command-line arguments and calculates in parallel both the sum and 
//  product from start to stop (inclusive) in increments of step. Be sure to use the 
//  proper reductions, and check to be sure that the results are correct. Call this sigma.c.

#include<stdio.h>
#include<stdlib.h>

int main(int argc, char* argv[]) {
    int start, stop, step, i = 0;
    long long sum = 0, prod = 1;

    // Input validation
    if(argc != 4) {
        printf("Usage: ./program start stop step\n");
        exit(EXIT_FAILURE);
    }

    // Get input
    start = atoi(argv[1]);
    stop = atoi(argv[2]);
    step = atoi(argv[3]);

    // Check for product = 0 due to no distance between bounds edge case
    if (stop - start <= 0 ) {
        printf("Sum: 0\n");
        printf("Product: 0\n");
        return 0;
    }

    // Do that work
# pragma omp parallel for reduction(*:prod), reduction(+:sum)
    for(i = start; i <= stop; i += step) {
        sum += i;
        prod *= i;
    }

    // Display result
    printf("Sum: %lld\n", sum);
    printf("Product: %lld\n", prod);

    return 0;
}
