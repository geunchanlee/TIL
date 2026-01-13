#include <stdio.h>
#define SETBIT(x, n) ((x) |= (1 << (n)))
#define CLEARBIT(x, n) ((x) &= ~(1 << (n)))
#define TESTBIT(x, n) ((x) & (1 << (n)))

int main()
{
    int x = 0x1011; // 8 (0001 0000 0001 0001)
    printf("SETBIT(x,8)전 변수 x = %x\n", x);
    SETBIT(x, 8);
}