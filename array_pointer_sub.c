#include <stdio.h>

int main(void)
{
  int a[10];
  printf("%ld\n", &a[2]);
  printf("%ld\n", a);
  printf("%ld\n", &a[2]-a);
  return 0;
}
