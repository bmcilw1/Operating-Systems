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

#include<sdtio.h>
#include<pthreads>

int main() {

    return 0;
}
