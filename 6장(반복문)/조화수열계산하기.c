#include <stdio.h>

int main()
{
    int n = 10000000;
    double i = 1;
    double sum = 0;

    while (i <= n)
    {
        sum += 1 / i;
        i++;
    }
    printf("수열의 합=%lf\n", sum);
}