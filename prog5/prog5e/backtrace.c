// Brian McIlwain
// Backtraces on segmentation fault.
// Write a program which uses a signal handler for SIGSEGV to print out more useful 
// information during a segmentation fault. Yours should print a backtrace for the process. 

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <execinfo.h>
#include <signal.h>

// https://www.gnu.org/software/libc/manual/html_node/Backtraces.html
void segv_handler(int signal) {
  void *array[10];
  size_t size;
  char **strings;
  size_t i;

  size = backtrace (array, 10);
  strings = backtrace_symbols (array, size);

  printf ("Obtained %zd stack frames.\n", size);

  for (i = 0; i < size; i++)
     printf ("%s\n", strings[i]);

  free (strings);
}

int main() {
    signal(SIGSEGV, segv_handler);
    
    while (1);

    return 0;
}
