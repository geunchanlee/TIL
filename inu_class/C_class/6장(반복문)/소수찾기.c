#include <stdio.h>
#define CRT_SECURE_NO_WARNINGS

int main()
{
    int n, i, j;
    i = 2;

    printf("어디까지 찾을까요?: ");
    scanf("%d", &n);

    while (i <= n)
    {
        int cnt = 0; // flag변수 소수인지 아닌지 알기 위해 쓰는 변수
        for (j = 2; j < i; j++)
        {
            if (i % j == 0)
            {
                cnt += 1;
            }
        }
        if (cnt == 0)
        {
            printf("%d ", i);
        }
        i += 1;
    }
    return 0;
}