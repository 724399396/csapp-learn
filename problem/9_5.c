#include "csapp.h"
#include <sys/stat.h>

int main(int argc, char** argv)
{
  if (argc != 2) {
    printf("usage: %s <filename>\n", argv[0]);
    exit(0);
  }

  int fd = Open(argv[1], O_RDONLY, 0);
  struct stat st;
  fstat(fd, &st);

  char *bufp = Mmap(NULL, st.st_size, PROT_READ, MAP_PRIVATE, fd, 0);
  Write(1, bufp, st.st_size);
}
