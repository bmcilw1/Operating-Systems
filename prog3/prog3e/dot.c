// Brian McIlwain
// Op Sys hw 3
// Calculating the dot product
//  Write a multi-threaded program using pthreads which calculates the dot product of 
//  two arrays u and v. To do this, split each of the arrays in half, calculate the dot 
//  products of the two halves, then add the results together. Create two threads to 
//  achieve this end. Assume that the sizes of u and v are even. Call it dot.c. In your 
//  output, show the two arrays u and v and the final result of the dot product.

#include<stdio.h>
#include<pthread.h>

// Array size
#define SIZE 4

typedef struct {
    double *u;
    double *v;
    int start;
    int end;
    double ret_val;
} dot_args;

void* dot(void* void_args);

int main() {
    // Input arrays
    double u[SIZE] = {0, 1, 2, 3};
    double v[SIZE] = {3, 2, 1, 0};
    
    // Default thread attr
    pthread_attr_t attr;
    pthread_attr_init(&attr);

    pthread_t tid[2];

    // Me args
    dot_args args1 = { .u = u, .v = v, .start = 0, .end = SIZE/2 };
    dot_args args2 = { .u = u, .v = v, .start = SIZE/2, .end = SIZE };

    // Spawn threads
    pthread_create(&tid[0], &attr, dot, &args1);
    pthread_create(&tid[1], &attr, dot, &args2);

    // Join upon completion
    pthread_join(tid[0], NULL);
    pthread_join(tid[1], NULL);

    // Get return value
    printf("dot: %f\n", args1.ret_val + args2.ret_val);

    return 0;
}

void* dot(void* void_args) {
    dot_args* args = (dot_args *)void_args;
    int i;

    for (i=args->start; i < SIZE && i < args->end; i++)
        args->ret_val += args->u[i]*args->v[i];

    return NULL;
}
