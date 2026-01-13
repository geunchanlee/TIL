#include <stdio.h>
#define CRT_SECURE_NO_WARNINGS
#define SIZE 10

int main()
{
    int key, index, i;
    int list[SIZE] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    printf("[");
    for (i = 0; i < SIZE; i++)
    {
        printf(" %d ", list[i]);
    }
    printf("]\n");

    printf("탐색할 값을 입력하세요: ");
    scanf("%d", &key);

    for (i = 0; i < SIZE; i++)
    {
        if (list[i] == key)
        {
            index = i;
            printf("탐색 성공 인덱스: %d\n", index);
            break;
        }
    }
    return 0;
}