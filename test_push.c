int main()
{
  asm("movl %esp, %eax");
  asm("pushl %esp");
  asm("popl %ebx");
  asm("subl %ebx, %eax");
}
