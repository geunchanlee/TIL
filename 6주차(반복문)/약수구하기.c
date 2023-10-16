#include <stdio.h>
#define CRT_SECURE_NO_WARNINGS

int main()
{
    int num,i;
    printf("정수를 입력하세요: ");
    scanf("%d",&num);

    for (i=1;i<=num;i++)
    {
        if (num % i == 0)
        {
            printf("%d ",i);
        }
    }
}