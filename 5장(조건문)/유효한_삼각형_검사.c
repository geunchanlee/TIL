#include <stdio.h>
#define CRT_SECURE_NO_WARNINGS

int main()
{
    int x, y, z;
    printf("삼각형의 세변 입력: ");
    scanf("%d,%d,%d", &x, &y, &z);

    if ((x + y > z) && (x + z > y) && (y + z > x))
        printf("유효한 삼각형\n");
    else
        printf("유효하지 않은 삼각형\n");
}