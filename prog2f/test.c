#include <stdio.h>

int main()
{
  FILE* test = popen("sleep 4 && echo done!", "r");

  if (test == NULL)
  {
    printf("FAIL!\n");
    return 1;
  }
  
  char buffer[1028];
  
  while (fgets(buffer, 1028, test) != NULL)
  {
    printf("%s", buffer);
  }
  
  pclose(test);
  printf("Success.\n");
  
  return 0;
} 
