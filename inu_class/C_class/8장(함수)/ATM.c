#include <stdio.h>
#define CRT_SECURE_NO_WARNINGS

int menu()
{
    int s;
    printf("**********Welcome to 콘서트 ATM**********\n");
    printf("****하나를 선택하세요****\n");
    printf("<1> 잔고 확인\n");
    printf("<2> 입금\n");
    printf("<3> 인출\n");
    printf("<4> 종료\n");
    scanf("%d", &s);
    return s;
}

int main()
{
    int a, b;
    int money = 0;
    while (1)
    {
        a = menu();
        if (a == 4)
        {
            printf("ATM 사용을 종료합니다.\n");
            break;
        }
        else if (a == 1)
        {
            printf("현재 잔고는 %d원 입니다.\n\n", money);
        }
        else if (a == 2)
        {
            printf("****입금 금액을 입력하세요\n");
            scanf("%d", &b);
            money += b;
            printf("새로운 잔고는 %d원 입니다.\n\n", money);
        }
        else if (a == 3)
        {
            printf("****인출 금액을 입력하세요\n");
            scanf("%d", &b);
            money -= b;
            printf("새로운 잔고는 %d원 입니다.\n\n", money);
        }
    }
}