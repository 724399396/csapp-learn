#include <stdio.h>
#include <limits.h>

int main() {
  int x = INT_MIN;
  int y = 0;

  unsigned ux = x;
  unsigned uy = y;

  printf("%d\n", (x > 0) || (x-1 < 0));
  printf("%d\n", x*x >= 0);
  printf("%d\n", x < 0 || -x <= 0);
  printf("%d\n", x > 0 || -x >= 0);
}
