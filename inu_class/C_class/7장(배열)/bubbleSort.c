#include <stdio.h>
#include <stdlib.h>
#define SIZE 10

int main(void)
{
    int list[SIZE] = {100, 30, 20, 78, 89, 12, 56, 38, 99, 66};

    for (int k = 0; k < SIZE; k++)
    {
        int flag = 0;
        system("clear");
        for (int i = 0; i < SIZE - k - 1; i++)
        {
            if (list[i] > list[i + 1])
            {
                int tmp = list[i];
                list[i] = list[i + 1];
                list[i + 1] = tmp;
                flag = 1;
            }
        }
        for (int i = 0; i < SIZE; i++)
        {
            for (int m = 0; m < list[i] / 10; m++)
                printf("*");
            printf("\n");
        }
        // 하나의 패스에서 교환이 한 번도 없으면 정렬 완료
        if (flag == 0)
            break;
        getchar();
    }
    return 0;
}