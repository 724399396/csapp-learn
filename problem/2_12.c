#include <stdio.h>

int main() {
  int x = 0x87654321;

  printf("%x\n", x & 0xff);
  printf("%x\n", (x & 0xff) | (~x & ~0xff));
  printf("%x\n", (x & ~0xff) | 0xff);
}
