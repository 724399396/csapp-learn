#include <stdio.h>

int lower_one_mask(int n)
{
  return ((1 << (n - 1)) << 1) - 1;
}

int main(void)
{
  printf("%d, %x\n", 6, lower_one_mask(6));
  printf("%d, %x\n", 17, lower_one_mask(17));
}
