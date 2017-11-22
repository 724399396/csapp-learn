#include "csapp.h"

int main(int argc, char *argv[], char *envp[])
{
  int i;
  printf("Command line arguments:\n");
  for (i = 0; i < argc; i++) {
    printf("argv[%2d]: %s\n", i, argv[i]);
  }

  printf("Environment variables:\n");
  i = 0;
  while (envp[i] != NULL) {
    printf("envp[%2d]: %s\n", i, envp[i]);
    i++;
  }

  return 0;
}
