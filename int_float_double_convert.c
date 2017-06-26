#include <stdio.h>
#include <limits.h>

int main()
{
  int x = INT_MAX;
  printf("%d %d\n", x, (int)(float)x);
  printf("%d %d\n", x, (int)(double)x);

  float f = 3.402823466e38;
  double d = 1.7e308;
  printf("%f %f\n", f, (float)(double)f);
  printf("%f %f\n", d, (double)(float)f);

  printf("%f %f\n", 1.0/2, 1/2.0);
  printf("%f %d\n", d*d, d*d > 0);
}
