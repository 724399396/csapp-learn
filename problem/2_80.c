#include <stdio.h>

int k_zero(unsigned k)
{
  return -1 << k;
}

int k_one_j_zero(unsigned k, unsigned j)
{
  return (-1 << j) &
    ~(-1 << (j+k));
}

int main(void)
{
  printf("%x %x %x %x\n", k_zero(10), k_zero(20), k_one_j_zero(1,1), k_one_j_zero(10,15));
}
