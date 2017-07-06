#include <stdio.h>
#include <limits.h>

int tsub_ok(int x, int y)
{
  int res = x - y;
  return ((x & INT_MIN) && !(y & INT_MIN) && (res & INT_MIN)) ||
    (!(x & INT_MIN) && (y & INT_MIN) && !(res & INT_MIN));
}

int main(void)
{
  printf("%x = %x - %x\n", INT_MAX-(-2), INT_MAX, -2);
}
