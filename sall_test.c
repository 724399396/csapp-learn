int main()
{
  asm("movl $8, %edx");
  asm("movl $1, %ecx");
  asm("sall %cl, %edx");
  return 0;
}
