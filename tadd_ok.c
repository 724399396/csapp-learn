int tadd_ok(int x, int y) {
  int res = x + y;
  return !((x < 0 && y < 0 && res > 0) || (x > 0 && y > 0 && res < 0));
}
