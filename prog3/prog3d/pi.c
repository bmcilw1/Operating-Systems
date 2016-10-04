// Brian McIlwain
// OpSys hw 3
// Approximating pi
//  Write a program using pthreads which approximates pi using the Monte Carlo technique.
//  In this technique, a unit circle (of area pi) is circumscribed inside a square (of 
//  area 4). Random numbers are generated within the square. The number which fall 
//  inside the circle (c) is counted, and divided by the total generated (t). For large t,
//  c/t approximates pi/4.
//  Write a multi-threaded program (using the C pthread library) which creates four 
//  threads to independently approximate pi using this technique; then average the 
//  results. Use t=10000 for each thread. Call this pi.c. Note that you will need to 
//  link against the pthreads library when compiling.

#include<stdio.h>
#include<pthread.h>

typedef struct {
    int t;
    long double ans;
} pi_args;

void * pi(void * void_args);

int main() {
    // Prep threads
    pthread_attr_t attr;
    pthread_attr_init(&attr);

    pthread_t tid[4];

    pi_args args[4] = {{ .t = 10000, .ans = 0 }, { .t = 10000, .ans = 0 }, { .t = 10000, .ans = 0 }, { .t = 10000, .ans = 0 }};

    int i;
    for (i = 0; i < 4; ++i)
        pthread_create(&tid[i], &attr, pi, &args[i]);

    for (i = 0; i < 4; ++i)
        pthread_join(tid[i], NULL);

    long double pi = 0;
    for (i = 0; i < 4; ++i)
        pi += args[i].ans;

    pi /= 4;

    printf("pi: %.50Lf\n", pi);

    return 0;
}

void * pi(void * void_args) {
    pi_args* args = (pi_args *)void_args;
    
    args->ans = 0;

    return NULL;
}
