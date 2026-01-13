#include <stdio.h>
#define CRT_SECURE_NO_WARNINGS

int main()
{
    int temp;
    printf("오늘의 기온을 입력하세요: ");
    scanf("%d", &temp);

    if (temp < -10)
        printf("매우 추운 날씨입니다.\n");
    else if (temp < 0)
        printf("추운 날씨입니다.\n");
    else if (temp < 10)
        printf("쌀쌀한 날씨입니다.\n");
    else if (temp < 20)
        printf("쾌적한 날씨입니다.\n");
    else if (temp < 30)
        printf("더운 날씨입니다.\n");
    else
        printf("무더운 날씨입니다.\n");
    return 0;
}