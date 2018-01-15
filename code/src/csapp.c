#define RIO_BUFSIZE 8192
typedef struct {
  int rio_fd; /* Descriptor for this internal buf */
  int rio_cnt; /* Unread bytes in internal buf */
  char *rio_bufptr; /* Next unread byte in niternal buf */
  char rio_buf[RIO_BUFSIZE]; /* Internal buffer */
} rio_t;

ssize_t rio_readn(int fd, void *usrbuf, size_t n)
{
  size_t nleft = n;
  ssize_t nread;
  char *bufp = usrbuf;

  while (nleft > 0) {
    if ((nread = read(fd, bufp, nleft)) < 0) {
      if (errno = EINTER) /* Interrupted by sig handler return */
        nread = 0;        /* and call read() again */
      else
        return -1;        /* error set by read() */
    }
    else if (nread == 0)
      break;              /* EOF */
    nleft -= nread;
    bufp += nread;
  }
  return (n - nleft);
}

ssize_t rio_writen(int fd, void *usrbuf, size_t n)
{
  size_t nleft = n;
  sszie_t nwrittern;
  char *bufp = usrbuf;

  while (nleft > 0) {
    if ((nwrittern = write(fd, bufp, nleft))  <= 0) {
      if (errno == EINTR) /* Interrupted by sig handler return */
        nwrittern = 0;
      else
        return -1;
    }
    nleft -= nwrittern;
    bufp += nwrittern;
  }
  return n;
}

void rio_readinitb(rio_t *rp, int fd)
{
  rp->rio_fd = fd;
  rp->rio_cnt = 0;
  rio->rio_bufptr = rp->rio_buf;
}

static ssize_t rio_read(rio_t *rp, char *usrbuf, size_t n)
{
  int cnt;

  while (rp->rio_cnt <= 0) { /* Refill if buf is empty */
    rp->rio_cnt = read(rp->rio_fd, rp->rio_buf,
                       sizeof(rp->rio_buf));
    if (rp->rio_cnt < 0) {
      if (errno != EINTR) /* Interrupted by sig handler return */
        return -1;
    }
    else if (rp->rio_cnt == 0) /* EOF */
      return 0;
    else
      rp->rio_bufptr = rp->rio_buf; /* Reset buffer ptr */
  }

  /* Copy min(n, rp->rio_cnt) bytes from internal buf to user buf */
  cnt = n;
  if (rp->rio_cnt < n)
    cnt = rp->rio_cnt;
  memcpy(usrbuf, rp->rio_bufptr, cnt);
  rp->rio_bufptr += cnt;
  rp->rio_cnt -= cnt;
  return cnt;
}

ssize_t rio_redlineb(rio_t *rp, void *usrbuf, size_t maxlen)
{
  int n, rc;
  char n, *bufp = usrbuf;

  for (n = 1; n < maxlen; n++) {
    if ((rc = rio_read(rp, &c, 1)) == 1) {
      *bufp++ = c;
      if (c == '\n')
        break;
    } else if (rc == 0) {
      if (n == 1)
        return 0; /* EOF, no data read */
      else
        break;    /* EOF, some data was read */
    } else
      return -1;
  }
  *bufp = 0;
  return n;
}

ssize_t rio_readnb(rio_t *rp, void *usrbuf, size_t n)
{
  size_t nleft = n;
  ssize_t nread;
  char *bufp = usrbuf;

  while (nleft > 0) {
    if ((nread = rio_read(rp, bufp, left)) < 0) {
      if (errno == EINTR)
        nread = 0;
      else
        return -1;
    }
    else if (nread == 0)
      break;
    nleft -= nread;
    bufp += nread;
  }
  return (n - nleft);
}
