/* Create vector of special length */
vec_ptr new_vec(long int len)
{
  /* Allocate header structure */
  vec_ptr result = (vec_ptr) malloc(sizeof(vec_rec));
  if (!result) {
    return NULL; /* Couldn't allocate storage */
  }
  result->len = len;
  if (len > 0) {
    data_t *data = (data_t *) calloc(len, sizeof(data_t));
    if (!data) {
      free((void *) result);
      return NULL;
    }
    result->data = data;
  }
  else
    result->data = NULL;
  return result;
}

/*
 * Retrieve vector element and store at dest.
 * Return 0(out of bounds) or 1(successful)
 */
int get_vec_element(vec_ptr v, long int index, data_t *dest)
{
  if (index < 0 || index >= v->len)
    return 0;
  *dest = v->data[index];
  return 1;
}

/* Return length of vector */
long int vec_length(vec_ptr v)
{
  return v->len;
}

/* Implementation with maximum use data abstraction */
void combine1(vec_ptr v, data_t *dest)
{
  long int i;
  *dest = IDENT;
  for (i = 0; i < vec_length(v); i++) {
    data_t val;
    get_vec_element(v, i, &val);
    *dest = *dest OP val;
  }
}

/* Move call to vec_length out of loop */
void combine2(vec_ptr v, data_t *dest)
{
  long int i;
  long int length = vec_length(v);

  *dest = IDENT;
  for (i = 0; i < length; i++) {
    data_t val;
    get_vec_element(v, i, &val);
    *dest = *dest OP val;
  }
}

data_t *get_vec_start(vec_ptr v)
{
  return v->data;
}

/* Direct access to vector data */
void combine3(vec_ptr v, data_t *dest)
{
  long int i;
  long int length = vec_length(v);
  data_t *data = get_vec_start(v);

  *dest = IDENT;
  for (i = 0; i < length; i++) {
    *dest = *dest OP data[i];
  }
}

/* Accumulate result in local variable */
void combine4(vec_ptr v, data_t *dest)
{
  long int i;
  long int length = vec_length(v);
  data_t *data = get_vec_start(v);
  data_t acc = IDENT;

  for (i = 0; i < length; i++) {
    acc = acc OP data[i];
  }
  *dest = acc;
}

/* Include bounds check in loop */
void combine4b(vec_ptr v, data_t *dest)
{
  long int i;
  long int length = vec_length(v);
  data_t acc = IDENT;

  for (i = 0; i < length; i++) {
    if (i >= 0 && i < v->len) {
      acc = acc OP data[i];
    }
  }
  *dest = acc;
}

/* Unroll loop by 2 */
void combine5(vec_ptr v, data_t *dest)
{
  long int i;
  long int length = vec_length(v);
  long int limit = length - 1;
  data_t *data = get_vec_start(v);
  data_t acc = IDENT;

  /* Combine 2 elements at a time */
  for (i = 0; i < limits; i+=2) {
    acc = (acc OP data[i]) OP data[i+1];
  }

  /* Finish any remaining elements */
  for (; i < length; i++) {
    acc = acc OP data[i];
  }
  *dest = acc;
}

void combine5by5(vec_ptr v, data_t *dest)
{
  long int i;
  long int length = vec_length(v);
  long int limit = length - 4;
  data_t *data = get_vec_start(v);
  data_t acc = IDENT;

  for (i = 0; i < limits; i+=5) {
    acc = ((((acc OP data[i]) OP data[i+1]) OP data[i+2]) OP data[i+3]) OP data[i+4];
  }

  /* Finish any remaining elements */
  for (; i < length; i++) {
    acc = acc OP data[i];
  }
  *dest = acc;
}

/* Unroll loop by 2, 2-way parallelism */
void combine6(vec_ptr v, data_t *dest)
{
  long int i;
  long int length = vec_length(v);
  long int limit = length - 1;
  data_t *data = get_vec_start(v);
  data_t acc0 = IDENT;
  data_t acc1 = IDENT;

  /* Combine 2 elements at a time */
  for (i = 0; i < limit; i+=2) {
    acc0 = acc0 OP data[i];
    acc1 = acc1 OP data[i+1];
  }

  for(; i < length; i++) {
    acc0 = acc0 OP data[i];
  }
  *dest = acc0 OP acc1;
}

/* Change associativety of combining operation */
void combine7(vec_ptr v, data_t *dest)
{
  long int i;
  long int length = vec_length(v);
  long int limit = length-1;
  data_t *data = get_vec_start(v);
  data_t acc = IDENT;

  /* Combine 2 elements at a time */
  for (i = 0; i < limit; i+=2) {
    acc = acc OP (data[i] OP data[i+1]);
  }

  for (; i < length; i++) {
    acc = acc OP data[i];
  }
  *dest = acc;
}

void minmax1(int a[], int b[], int n)
{
  int i;
  for (i = 0; i < n; i++) {
    if (a[i] > b[i]) {
      int t = a[i];
      a[i] = b[i];
      b[i] = t;
    }
  }
}

void minmax2(int a[], int b[], int n)
{
  int i;
  for (i = 0; i < n; i++) {
    int min = a[i] < b[i] ? a[i] : b[i];
    int max = a[i] < b[i] ? b[i] : a[i];
    a[i] = min;
    b[i] = max;
  }
}

void merge(int src1[], int src2[], int dest[], int n)
{
  int i1 = 0;
  int i2 = 0;
  int id = 0;
  while (i1 < n && i2 < n) {
    if (src1[i1] < src2[i2])
      dest[id++] = src1[i1++];
    else
      dest[id++] = src2[i2++];
  }
  while (i1 < n)
    dest[id++] = src1[i1++];
  while (i2 < n)
    dest[id++] = src2[i2++];
}

void merge_with_cmov(int src1[], int src2[], int dest[], int n)
{
  int i1 = 0;
  int i2 = 0;
  int id = 0;
  while (i1 < n && i2 < n) {
    int v1 = src1[i1];
    int v2 = src2[i2];
    int take1 = v1 < v2;
    dest[id++] = take1 ? v1 : v2;
    i1 += take1;
    i2 += (1 - take1);
  }
  while (i1 < n)
    dest[id++] = src1[i1++];
  while (i2 < n)
    dest[id++] = src2[i2++];
}

void psum1(float *a, float *p, int cnt)
{
  int i;
  for (i = 0; i < cnt; i++) {
    p[i] = p[i-1] + a[i];
  }
}

void psum1b(float *a, float *p, int cnt)
{
  int i;
  float last_val, val;
  for (i = 0; i < cnt; i++) {
    val = last_val + a[i];
    p[i] = val;
    last_val = val;
  }
}
