int divide_power2(int x, int k)
{
  int sign = x & INT_MIN;
  int rounding = (1 << k) - 1;
  return (x + (sign << 31 & rounding)) >> k;
}

int mul3div4(int x)
{
  int div4 = divide_power2(x, 2);
  return div4 + div4 << 1;
}
