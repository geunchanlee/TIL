#include <math.h>
#include <stdio.h>
#define CRT_SECURE_NO_WARNINGS

int main()
{
    int a, b, c;
    double x, y;
    printf("계수 a,b,c를 입력하세요: ");
    scanf("%d %d %d", &a, &b, &c);

    double d;
    d = (b * b) - (4 * a * c);
    printf("%lf", d);
    if (a == 0)
    {
        x = -c / b;
        printf("근: %f\n", x);
    }
    else if (d >= 0)
    {
        x = (-b + sqrt(d)) / (2.0 * a);
        y = (-b - sqrt(d)) / (2.0 * a);
        printf("첫번째 실근: %f\n", x);
        printf("두번째 실근: %f\n", y);
    }
    else
        printf("허수근");
}