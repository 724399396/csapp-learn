typedef unsigned packed_t;

int xbyte(packaed_t word, int bytenum)
{
  return ((int) word << ((3 - bytenum) << 3)) >> 24;
}
