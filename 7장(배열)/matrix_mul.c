#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define ROW 3
#define COL 2

int main()
{
    srand(time(NULL));
    int i, j;
    int a[ROW][COL];
    int b[COL][ROW];
    int c[ROW][ROW];

    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < ROW; j++)
            c[i][j] = 0;
    }
}
