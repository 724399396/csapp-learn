float fpwr2(int x)
{
  /* Result exponent and fraction */
  unsigned exp, frac;
  unsigned u;
  if (x <  (-149)) {
    /* Too small. Return 0.0 */
    exp =  0;
    frac = 0;
  } else if (x < -126) {
     /* Denormalized result */
    exp =  0;
    frac =  1 << (149 + x);
  } else if (x < 128) {
    Homework Problems 131
    /* Normalized result. */
      exp = x+126;
      frac =  0;
  } else {
    /* Too big.  Return +oo */
    exp =  0x11111111;
    frac = 0;
  }
  /* Pack exp and frac into 32 bits */
  u = exp << 23 | frac;
  /* Return as float */
  return u2f(u);
}
