#include <stdio.h>

int main()
{
    int i, j;
    int a[3][3] = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
    int b[3][3] = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            int sum = a[i][j] + b[i][j];
            printf("%d ", sum);
        }
        printf("\n");
    }
    return 0;
}