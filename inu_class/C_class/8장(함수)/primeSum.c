#include <stdio.h>
#define CRT_SECURE_NO_WARNINGS
int primeCheck(int n);
int primeSum(int i);

int main()
{
    int k;
    printf("양의 정수를 입력하세요: ");
    scanf("%d", &k);
    primeSum(k);
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

int primeSum(int i)
{
    for (int j = 2; j < i; j++)
    {
        if (primeCheck(j) == 1)
        {
            printf("%d = %d + %d\n", i, j, i - j);
        }
    }
    return 0;
}