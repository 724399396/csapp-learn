#include "csapp.h"

unsigned int snooze(unsigned int secs)
{
  unsigned int left = sleep(secs);
  printf("Slept for %d of %d secs\n", secs - left, secs);
  return left;
}

void handler(int sig) {
  return;
}

int main(int argc, char *argv[])
{
  if (argc != 2) {
    fprintf(stderr, "usage: %s <secs>\n", argv[0]);
    exit(0);
  }

  if (signal(SIGINT, handler) == SIG_ERR)
    unix_error("signal error");

  snooze(atoi(argv[1]));
  exit(0);
}
