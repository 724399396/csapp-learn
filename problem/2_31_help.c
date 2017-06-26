#include "bi_check.h"
#include <stdio.h>

int main()
{
  int x = 0x7fffffff;
  int y = 0x7fffffff;
  int sum = x + y;
  show_int(sum);
  show_int(sum-x);
  show_int(sum-y);
  printf("%d = %d + %d\n", sum, x, y);

  int product = x * y;
  show_int(product);
  show_int(product/x);
  printf("%d = %d * %d\n", product, x, x);

  int prod2 = x * 2;
  show_int(prod2);
  show_int(prod2/2);
  printf("%d = %d * %d\n", prod2, x, 2);

}
