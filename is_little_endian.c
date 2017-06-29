#include <stdio.h>

int main(void)
{
  int test_data = 0x01;

  int res = *(unsigned char*)(&test_data) == 1;

  if (res) {
    printf("little endian\n");
  } else {
    printf("big endian\n");
  }
}
