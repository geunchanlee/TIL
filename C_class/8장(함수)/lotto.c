#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 45

int main()
{
    int i, k, lotto[6] = {0};
    int dup_check[MAX + 1] = {0}; // 중복 검사할 배열 dup_check

    srand(time(NULL));
    for (i = 0; i < 6; i++)
    {
        k = 1 + rand() % MAX;
        while (dup_check[k] == 1)
            k = 1 + (rand() % MAX);
        lotto[i] = k;
        dup_check[k] = 1;
        printf("%d ", lotto[i]);
    }
    printf("\n");
    return 0;
}