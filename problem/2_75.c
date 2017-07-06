unsigned int unsigned_high_prod(unsigned x, unsigned y);

int signed_high_prod(int x, int y)
{
  return (int)unsigned_high_prod(x, y) - x * !!(y & INT_MIN) - y * !!(x & INT_MIN);
}
