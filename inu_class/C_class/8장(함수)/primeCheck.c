#include <stdio.h>
#define CRT_SECURE_NO_WARNINGS

int primeCheck(int n); // 함수 원형 작성

int main()
{
    int n;
    printf("정수를 입력하세요: ");
    scanf("%d", &n);
    if (primeCheck(n) == 1)
        printf("소수입니다.\n");
    else
        printf("소수가 아닙니다.\n");
    return 0;
}

int primeCheck(int n)
{
    int i, prime;
    for (i = 2; i < n; i++)
    {
        if (n % i == 0)
            prime = 0;
        else
            prime = 1;
    }
    return prime;
}