#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL));
    // niter = 반복횟수
    int niter, inside_dots = 0;
    double x, y, z, pi;

    printf("반복횟수: ");
    scanf("%d", &niter);

    inside_dots = 0;

    for (int i = 0; i < niter; i++)
    {
        x = (double)rand() / RAND_MAX;
        y = (double)rand() / RAND_MAX;
        z = x * x + y * y;
        if (z <= 1)
            inside_dots++;
    }
    pi = (double)inside_dots / niter * 4;
    printf("파이 = %lf\n\n", pi);
    return 0;
}