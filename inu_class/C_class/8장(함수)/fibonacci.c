#include <stdio.h>
int fib(int n);

int main()
{
    int n;
    printf("피보나치 수열: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        printf("%d ", fib(i));
    }
    printf("\n");
    return 0;
}

int fib(int n)
{
    if (n <= 1)
        return n;
    else
    {
        return (fib(n - 1) + fib(n - 2)); // 순환 호출로 피보나치 수열 찾기
    }
}