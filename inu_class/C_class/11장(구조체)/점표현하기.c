#include <stdio.h>
#define CRT_SECURE_NO_WARNINGS
#include <math.h>

struct point
{
    int x;
    int y;
};

int main()
{
    struct point p1, p2;

    double xdiff, ydiff;
    double dist;

    // 구조체 변수 선언하고 값 넣는것 보기
    printf("점의 좌표를 입력하세요(x y): ");
    scanf("%d %d", &p1.x, &p1.y);

    printf("점의 좌표를 입력하세요(x y): ");
    scanf("%d %d", &p2.x, &p2.y);

    xdiff = p1.x - p2.x;
    ydiff = p1.y - p2.x;

    dist = sqrt(xdiff * xdiff + ydiff * ydiff);

    return 0;
}