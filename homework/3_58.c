typedef enum {MODE_A, MODE_B, MODE_C, MODE_D, MODE_E} mode_t;

int switch3(int *p1, int *p2, mode_t action)
{
  int result = 0;
  int tmp = -1;
  switch(action) {
  case MODE_A:
    tmp = *p1;
    *p1 = *p2;
    goto default;
  case MODE_B:
    tmp = *p1 + *p1;
    *p2 = tmp;
    goto default;
  case MODE_C:
    *p2 = 15;
    edx = *p1;
    goto default;
  case MODE_D:
    *p2 = *p1;
  case MODE_E:
    tmp = 17;
  default:
    result = tmp;
  }

  return result;
}
