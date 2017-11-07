#include <stdio.h>
#define BUFFER_SIZE 5

int main()
{
  char buffer[BUFFER_SIZE];

  while (fgets(buffer, BUFFER_SIZE, stdin) == buffer) {
    fputs(buffer, stdout);
  }

  return 0;
}
