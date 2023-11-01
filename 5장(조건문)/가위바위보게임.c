#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#define CRT_SECURE_NO_WARNINGS

int main()
{
    int a;
    printf("가위, 바위, 보 게임에 오신 것을 환영합니다.\n");
    printf("하나를 선택하세요(가위 -0, 바위-1, 보-2): ");
    scanf("%d", &a);

    srand(time(NULL));
    int com = rand() % 3;
    printf("사용자 = %d\n", a);
    printf("컴퓨터 = %d\n", com);

    if (a == com)
        printf("비겼습니다\n");
    else if (a == (com + 1 % 3))
        printf("사용자 승리\n");
    else
        printf("사용자 패배\n");

    return 0;
}
