#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int main(int argc, char **argv)
{
  if (argc != 2) {
    printf("usage: hex2dd hex\n");
    exit(0);
  }
  if (strlen(argv[1]) != 10) {
    printf("please correct input format %zu\n", strlen(argv[1]));
    exit(0);
  }

  int i;
  char str[5];
  char *prefix = "0x";
  for (i = 0; i < 4; i++) {
    memcpy(str, prefix, 2);
    memcpy(str+2, argv[1]+2+2*i, 2);
    long decimal = strtol(str, NULL, 16);
    printf("%zu", decimal);
    if (i != 3) {
      printf(".");
    } else {
      printf("\n");
    }
  }
}
