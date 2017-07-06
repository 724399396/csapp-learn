#include <stdio.h>
#include <limits.h>

int saturating_add(int x, int y)
{
  int res = x + y;
  int x_sign_mask = x >> 31;
  int y_sign_mask = y >> 31;
  int res_sign_mask = res >> 31;
  int pos_over_mask = ~x_sign_mask & ~y_sign_mask & res_sign_mask;
  int neg_over_mask = x_sign_mask & y_sign_mask & ~res_sign_mask;
  int normal_mask = ~pos_over_mask & ~neg_over_mask;
  return (res & normal_mask) | (INT_MAX & pos_over_mask) | (INT_MIN & neg_over_mask);
}

int main(void)
{
  printf("%d = %d + %d\n", saturating_add(4, 4), 4, 4);
  printf("%d = %d + %d\n", saturating_add(4, INT_MAX), 4, INT_MAX);
  printf("%d = %d + %d\n", saturating_add(INT_MAX, INT_MAX), INT_MAX, INT_MAX);
  printf("%d = %d + %d\n", saturating_add(-2, -3), -2, -3);
  printf("%d = %d + %d\n", saturating_add(-2, INT_MIN), -2, INT_MIN);
  printf("%d = %d + %d\n", saturating_add(INT_MIN, INT_MIN), INT_MIN, INT_MIN);
}
