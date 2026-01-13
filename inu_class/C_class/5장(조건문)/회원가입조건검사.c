#include <stdio.h>
#define CRT_SECURE_NO_WARNINGS

int main(void)
{
    int math, phy, chemy;
    printf("수학, 물리, 화학 점수를 한줄에 입력하세요:");
    scanf("%d,%d,%d", &math, &phy, &chemy);

    if (math < 50 && phy < 50 && chemy < 50) 
        printf("가입할 수 없습니다.\n");
    else  {
        if (math + phy >= 150 || chemy + math >= 150)
            printf("가입할 수 있습니다.\n");
        else
            printf("가입할 수 없습니다.\n");
    }
    return 0;   
}