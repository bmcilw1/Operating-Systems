#include <stdio.h>
#include <string.h>

int greet(char *name) {
  char hello[32] = "Hello ";
  strcat(hello, name);
  printf("%s!\n", hello);

  return 0;
}

int main(int argc, char **argv) {
  if (argc > 1)
    greet(argv[1]);

  return 0;
}
