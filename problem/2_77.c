#include <limits.h>
#inlcude <stdio.h>

int divide_power2(int x, int k)
{
  int sign = x & INT_MIN;
  int rounding = (1 << k) - 1;
  return (x + (sign << 31 & rounding)) >> k;
}
