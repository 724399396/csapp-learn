#include <stdio.h>

int odd_ones(unsigned x)
{
  x ^= x << 16;
  x ^= x << 8;
  x ^= x << 4;
  x ^= x << 2;
  x ^= x << 1;
  return x & 1;
}

int main(void)
{
  printf("%d %d %d\n", odd_ones(0), odd_ones(1), odd_ones(2));
}
