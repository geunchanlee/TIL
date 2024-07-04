#include <stdio.h>
#include <stdlib.h>
#define CRT_SECURE_NO_WARNINGS

int main()
{
    int stick = 12;
    int a;
    int user, com;
    printf("현재 스틱의 개수: %d\n", stick);

    while (stick >= 0)
    {
        printf("몇 개의 스틱을 가져가시겠습니까?: ");
        scanf("%d", &user);
        stick = stick - user;
        if (stick <= 0)
        {
            printf("졌습니다.");
            break;
        }
        com = rand() % 3 + 1;
        printf("** 컴퓨터는 %d개의 스틱을 가져갔습니다.\n", com);
        stick = stick - com;
        if (stick - com <= 0)
        {
            printf("이겼습니다.");
            break;
        }
        printf("현재 스틱의 개수: %d\n\n", stick);
    }
}