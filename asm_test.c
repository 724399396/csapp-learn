int main()
{
  asm("movl $1, %eax");
  asm("leal (,%eax,4), %ecx");
  asm("movl (,%eax,4), %edx");
  return 0;
}
