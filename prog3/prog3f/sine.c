// Brian McIlwain
// Op Sys hw 3
// Calculating Sine
//  Using OpenMP, write a program which accepts a floating-point number as a 
//  command-line argument then calculates the sine, cosine, and tangent of the number. 
//  Write the function double sin(double x) which calculates the sine of a given argument 
//  x in parallel using the Taylor series formula for the sine function. Obtain the 
//  cosine and tangent using trigonometric identities. Output the results. Call this sine.c.

#include<stdio.h>
#include<stdlib.h>

double sin(double x);

int main(int argc, char* argv[]) {
    int i = 0;
    double num;

    // Input validation
    if(argc != 2) {
        printf("Usage: ./program num\n");
        exit(EXIT_FAILURE);
    }

    // Get input
    num = atof(argv[1]);

    // Display result
    printf("sin: %d\n", sin(num));
    printf("cos: %d\n", sin(num));
    printf("tan: %d\n", sin(num));

    return 0;
}

double sin(double x) {
    return 0;
}
