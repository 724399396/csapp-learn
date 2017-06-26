#include <stdio.h>

int main()
{
  int a = 0xffffffff;
  int b = 0x80000000;
  printf("%d\n", a + b);
  printf("%d\n", 0x7fffffff);
  return 0;
}
