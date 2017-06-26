#include <stdio.h>

int div16(int x)
{
    int sign = (x >> 31);
    return (x + (sign & 0x0F )) >> 4;
}

int main()
{
    printf("%d = %d / 16\n", div16(238), 238);
    printf("%d = %d / 16\n", div16(-238), 238);
}
