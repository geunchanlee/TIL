#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 1000

int main()
{
    srand(time(NULL));
    int n;
    int *num = NULL; // 동적할당을 위한 포인터는 꼭 항상 NULL로 초기화하기
    num = (int *)malloc(SIZE * sizeof(int));
    if (num == NULL)
    {
        fprintf(stderr, "메모리 할당 오류\n");
        exit(1);
    }
    for (int i = 0; i < SIZE; i++)
    {
        num[i] = rand();
    }
    for (int i = 0; i < SIZE; i++)
    {
        printf("%d ", num[i]);
    }

    // 최대값도 찾기
    int max = 0;
    for (int i = 0; i < SIZE; i++)
    {
        if (max < num[i])
            max = num[i];
    }
    printf("\n최댓값은: %d\n", max);
    free(num);
    return 0;
}