#include <stdio.h>

int main()
{
  int test = 0xff;

  int res = (*((unsigned char *)&test)) == 0xff;

  printf("%d\n", res);
}
