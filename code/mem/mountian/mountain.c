double data[MAXELEMS]; /* The global array we'll be traversing */

/*
 * test - Iterate over first "elems" elements of array "data"
 *        with stride of "stride".
 */
void test(int elems, int stride) /* The test function */
{
  int i;
  double result = 0.0;
  volatile double sink;

  for (i = 0; i < elems; i += stride) {
    result += data[i];
  }
  sink = result; /* So compiler doesn't optimize away the loop */
}

/*
 * run - Run test(elems, stride) and return read throughput (MS/s).
 *       "size" is in bytes, "stride" is in array elements, and
 *       Mhz is CPU clock frequency in Mhz.
*/
double run(int size, int stride, double Mhz)
{
  double cycles;
  int elems = size / sizeof(double);

  test(elems, stride);                     /* warm up the cache */
  cycles = fcyc2(test, elems, stride, 0);  /* call test(elems, stride) */
  return (size / stride) / (cycles / Mhz); /* convert cycles to MS/s */
}
