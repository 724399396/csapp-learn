typedef long long ll_t;

void store_prod(ll_t *dest, int x, ll_t y) {
  *dest = x*y;
}

int main(void)
{
  ll_t x;
  store_prod(&x, 2, 3);
  return 0;
}
