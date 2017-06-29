#include <stdio.h>

int any_one(int x)
{
  return x != 0;
}

int any_zero(int x)
{
  return (~x) != 0;
}

int least_significant_any_one(int x)
{
  return (x & 0xff)  != 0;
}

int most_significant_any_zero(int x)
{
  return ((x >> ((sizeof(int) -1) >> 3) ) & 0xff) != 0xff;
}

int main(void)
{
  printf("any one %d %d\n", 3, any_one(3));
  printf("any one %d %d\n", 0, any_one(0));

  printf("any zero %d %d\n", -1, any_zero(-1));
  printf("any zero %d %d\n", 328, any_zero(328));

  printf("least significant any one %d %d\n", 3, least_significant_any_one(3));
  printf("least significant any one %d %d\n", 1024, least_significant_any_one(1024));

  printf("most significant any zero %d %d\n", -1, most_significant_any_zero(-1));
  printf("most significant any zero %d %d\n", 1024, most_significant_any_zero(1024));
}
