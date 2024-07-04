#include <stdio.h>
#include <math.h>
#define CRT_SECURE_NO_WARNINGS

long double factorial(int n) // n이 100 처럼 큰 값일 때 계산을 위해 int가 아닌 long double을 사용
{
    long double result = 1.0;
    for (int i = n; i > 0; i--)
    {
        result *= i;
    }
    return result;
}

int main()
{
    int x, n;
    double r = 0;
    printf("x와 n의 값을 입력하시오: ");
    scanf("%d %d", &x, &n);

    for (int i = 0; i < n; i++)
    {
        r += pow(x, i) / factorial(i);
    }
    printf("e^2 = %.3lf\n", r);
    return 0;
}