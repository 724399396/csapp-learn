int A[5][9][11];

int store_ele(int i, int j, int k, int *dest)
{
  *dest = A[i][j][k];
  return sizeof(A);
}
