#include <stdio.h>
#define and &&

int main()
{
    int credits;
    double average;
    printf("지금까지 획득한 학점수를 입력하세요: ");
    scanf("%d", &credits);
    printf("지금까지 획득한 학점평균을 입력하세요: ");
    scanf("%lf", &average);
    if (credits >= 120 and average >= 2.0)
        printf("졸업 가능합니다.\n");
    else
        printf("졸업이 힘듭니다.\n");
    return 0;
}