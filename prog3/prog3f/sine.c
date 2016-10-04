// Brian McIlwain
// Op Sys hw 3
// Calculating Sine
//  Using OpenMP, write a program which accepts a floating-point number as a 
//  command-line argument then calculates the sine, cosine, and tangent of the number. 
//  Write the function double sin(double x) which calculates the sine of a given argument 
//  x in parallel using the Taylor series formula for the sine function. Obtain the 
//  cosine and tangent using trigonometric identities. Output the results. Call this sine.c.

// Define precision
#define FACT_MAX 15

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<limits.h>


double sin(double x);
double fact(int x);

// Dynamic programming var
double fact_arr[FACT_MAX*2 + 1] = {0};

int main(int argc, char* argv[]) {
    double num;

    // Input validation
    if(argc != 2) {
        printf("Usage: ./program num\n");
        exit(EXIT_FAILURE);
    }

    // Get input
    num = atof(argv[1]);

    // Display result
    printf("sin: %f\n", sin(num));
    printf("cos: %f\n", sin(num + M_PI/2));
    printf("tan: %f\n", sin(num)/sin(num + M_PI/2));

    return 0;
}

double sin(double x) {
    double ans = 0;
    int i;

# pragma omp parallel for reduction(+:ans)
    for (i = 0; i < FACT_MAX; i++)
        ans += pow(-1, i) * (pow(x, 2*i+1)/fact(2*i+1));

    return ans;
}

// Factorial using dynamic programming
double fact(int x) {
    if (x <= 1)
        return 1;
    else if (fact_arr[x] == 0) {
        printf("x fact cache: %i\n", x);
        fact_arr[x] = x*fact(x-1);
    }

    return fact_arr[x];
}
