#include <stdio.h>

unsigned replace_byte(unsigned x, int i, unsigned char b)
{
  int mask = ((1 << (8*i+8))-1)>> 8*i << 8*i;
  return (x & (~mask)) | (b << (8*i));
}

int main()
{

  printf("%x\n", replace_byte(0x12345678, 2, 0xAB));
  printf("%x\n", replace_byte(0x12345678, 0, 0xAB));

}
