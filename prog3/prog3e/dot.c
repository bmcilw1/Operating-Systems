// Brian McIlwain
// Op Sys hw 3
// Calculating the dot product
//  Write a multi-threaded program using pthreads which calculates the dot product of 
//  two arrays u and v. To do this, split each of the arrays in half, calculate the dot 
//  products of the two halves, then add the results together. Create two threads to 
//  achieve this end. Assume that the sizes of u and v are even. Call it dot.c. In your 
//  output, show the two arrays u and v and the final result of the dot product.

#include<stdio.h>
#define SIZE 2

double dot(double &[]u, double &[]v);

int main() {
    double u[SIZE] = {0, 1};

    double v[SIZE] = {3, 2};

    printf("dot: %f\n", dot(u,v));

    return 0;
}

double dot(double &[]u, double &[]v) {
    double ans = 0;
    int i;

    for (i=0; i < SIZE; i++)
        ans += u[i]*v[i];

    return ans;
}
