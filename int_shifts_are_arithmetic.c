#include <stdio.h>

int int_shifts_are_arithmetic()
{
  int test_data = -1;
  return (test_data >> ((sizeof(int) << 3) - 1)) == -1;
}

int main(void)
{
  printf("%d\n", int_shifts_are_arithmetic());
}
