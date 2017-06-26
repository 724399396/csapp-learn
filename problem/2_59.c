#include <stdio.h>

int main()
{
  int x = 0x89ABCDEF;
  int y = 0x76543210;

  printf("%x\n", (x & 0xff) | (y & (~0xff)));
}
