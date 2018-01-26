#include "csapp.h"

int main(int argc, char **argv)
{
  if (argc != 2) {
    fprintf(stderr, "usage: %s <hex number>\n", argv[0]);
    exit(0);
  }

  struct in_addr addr;
  inet_aton(argv[1], &addr);
  printf("0x%x\n", ntohl(addr.s_addr));
}
