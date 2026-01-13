#include <stdio.h>
#include <stdlib.h>
#define SIZE 10

int main()
{
    int price[SIZE] = {0};
    int i, min, max;
    for (i = 0; i < SIZE; i++)
    {
        int p = rand() % 40;
        price[i] = p;
    }

    min = max = price[0];

    for (i = 1; i < SIZE; i++)
    {
        if (price[i] < min)
        {
            min = price[i];
        }
        if (price[i] > max)
            max = price[i];
    }
    printf("최소값은 %d입니다.\n", min);
    printf("최대값은 %d입니다.\n", max);
    return 0;
}