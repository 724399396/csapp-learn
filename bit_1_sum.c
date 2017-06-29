int bit_one_sum(unsigned x)
{
  int phase_1_a = x & 0x55555555;
  int phase_1_b = (x << 1) & 0x55555555;
  int phase_1_res = phase_1_a + phase_1_b;

  int phase_2_a = phase_1_res & 0x33333333;
  int phase_2_b = (phase_1_res << 2) & 0x33333333;
  int phase_2_res = phase_2_a + phase_2_b;

  int phase_3_a = phase_2_res & 0x0F0F0F0F;
  int phase_3_b = (phase_2_res << 4) & 0x0F0F0F0F;
  int phase_3_res = phase_3_a + phase_3_b;

  int phase_4_a = phase_3_res & 0x00FF00FF;
  int phase_4_b = (phase_3_res << 8) & 0x00FF00FF;
  int phase_4_res = phase_4_a + phase_4_b;

  int phase_5_a = phase_4_res & 0x0000FFFF;
  int phase_5_b = (phase_4_res << 16) & 0x0000FFFF;
  int phase_5_res = phase_5_a + phase_5_b;

  return phase_5_res;
}
