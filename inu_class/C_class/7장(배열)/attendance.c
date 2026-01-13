#include <stdio.h>
#define CRT_SECURE_NO_WARNINGS
#define SIZE 16

int main(void)
{
    int i, cnt;
    double r = 0;
    int check[SIZE] = {0};

    for (i = 1; i <= SIZE; i++)
    {
        printf("%d번째 강의에 출석하셨나요 (출석은1, 결석은 0):", i);
        scanf("%d", &check[i]);
    }
    cnt = 0;
    for (i = 1; i <= SIZE; i++)
    {
        if (check[i] == 0)
        {
            cnt++;
        }
    }
    r = cnt / 16.0;

    printf("%f%%\n", r * 100.0);
    return 0;
}