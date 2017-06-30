#include <stdio.h>

int fits_bits(int x, int n)
{
  int mask = ~0 << (n-1);
  int higher_bit = x & mask;
  return (higher_bit == 0) || (higher_bit == mask);
}

int main(void)
{
  printf("%d %d %d %d\n",
         fits_bits(7, 4),
         fits_bits(-8, 4),
         fits_bits(8, 4),
         fits_bits(-9, 4));
}
