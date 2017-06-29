#include <stdio.h>

int w = sizeof(int)<<3;
int any_odd_one(unsigned x)
{
  int mask = 0x55555555;
  return (x & mask) != 0;
}

int main(void)
{
  for (int i = 0; i < 10; i++) {
    printf("%d %d\n", i, any_odd_one(i));
  }
}
