#include <stdio.h>
#include <stdlib.h>
#define CRT_SECURE_NO_WARNINGS

int main()
{
    int x, y, z;
    int answer;
    printf("산수 문제를 자동으로 출제합니다.\n");

    while (1)
    {
        x = rand() % 100;
        y = rand() % 100;
        z = x + y;

        printf("%d + %d = ", x, y);
        scanf("%d", &answer);
        if (answer == z)
        {
            printf("맞았습니다.\n");
            break;
        }
        else
        {
            printf("틀렸습니다.\n");
        }
    }
}