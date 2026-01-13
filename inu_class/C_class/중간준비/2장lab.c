// 4칙 연산
#include <stdio.h>
#define CRT_SECURE_NO_WARNINGS

int main(void)
{
    int i, j;
    printf("첫 번째 숫자를 입력하세요: ");
    scanf("%d", &i);
    printf("두 번째 숫자를 입력하세요: ");
    scanf("%d", &j);

    printf("두 수의 합: %d\n", i + j);
    printf("두 수의 차: %d\n", i - j);
    printf("두 수의 곱: %d\n", i * j);
    printf("두 수의 몫: %d\n", i / j);

    return 0;
}