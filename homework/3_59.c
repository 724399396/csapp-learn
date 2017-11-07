int switch_prob(int x, int n)
{
  int result = x;
  
  switch(n) {
  case 0:
  case 2:
    result /= 4;
    break;
  case 3:
    result = result >> 2;
    break;
  case 4:
    result *= 3;
    result = result * result;
  default:
    result += 10;
  }

  return result;
}
