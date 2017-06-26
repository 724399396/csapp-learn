#include <stdio.h>

int main()
{
  printf("%d\n", -1 < 0);
  printf("%d\n", -1 < 0U);

  unsigned int a = 0;
  printf("%d\n", -1 < a);
}
