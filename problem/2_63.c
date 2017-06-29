#include <stdio.h>

int w = sizeof(int) << 3;

unsigned srl(unsigned x, int k)
{
  unsigned csra = (int) x >> k;

  return csra & ((1 << (w - k)) - 1);
}

int sra(int x, int k)
{
  int xsrl = (unsigned) x >> k;

  int signbit = (x >> (w-1)) & 0x01;

  return xsrl | (((!signbit) + -1) << (w - k));
}

int main(void)
{
  printf("srl %d %d %d\n", -1, 2, srl(-1, 2));
  printf("srl %d %d %d\n", 1024, 2, srl(1024, 2));

  printf("sra %d %d %d\n", -1, 2, sra(-1, 2));
  printf("sra %d %d %d\n", 1024, 2, sra(1024, 2));
}
