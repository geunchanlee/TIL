#include <stdio.h>
#include <stdlib.h>
#define CRT_SECURE_NO_WARNINGS

int main()
{
    int n;
    int *num;

    printf("항목의 개수는 몇개입니까? :");
    scanf("%d", &n);

    num = (int *)malloc(n * sizeof(int));
    if (num == NULL)
    {
        fprintf(stderr, "메모리 할당 오류\n");
        exit(1);
    }

    for (int i = 0; i < n; i++)
    {

        printf("항목(정수)을 입력하세요: ");
        scanf("%d", &num[i]);
    }

    printf("입력된 값은 \n");

    free(num);
    return 0;
}