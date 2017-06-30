#include <stdio.h>

unsigned rotate_left(unsigned x, int n)
{
  int left_part_mask = ~0 << n;
  int right_part_mask = ~left_part_mask;

  return ((x << n) & left_part_mask) | ((x >> (32 -n)) & right_part_mask);
}

int main(void)
{
  printf("%x\n", rotate_left(0x12345678, 4));
  printf("%x\n", rotate_left(0x12345678, 20));
  printf("%x\n", rotate_left(0x12345678, 0));
}
