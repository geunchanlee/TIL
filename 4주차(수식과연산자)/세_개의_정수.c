#include <stdio.h>
#define CRT_SECURE_NO_WARNINGS

int main()
{
    int x, y, z;
    int bigNum;

    printf("3개의 정수를 입력하세요: ");
    scanf("%d %d %d", &x, &y, &z);

    // 조건연산자 이용해서 해보기
    bigNum = (x > y) ? x : y;
    bigNum = (bigNum > z) ? bigNum : z;

    // 조건연산자 이용해서 해보기2
    //  bigNum = (x > y) ? ((x > z) ? x : z) : ((y > z) ? y : z)
    //  x > y 면 앞 문장 실행 아니면 뒷 문장 실행 (조건연산자 뒤에 조건연산자가 오는 중첩)

    printf("가장 큰 정수는 %d입니다\n", bigNum);
    return 0;
}
/*  조건문을 통해 하는 방법 2가지
    big = x
    if (y > big) big = y
    if (z > big) big = z
    printf(big)


    if (x > y && x > z)
        bigNum = x;
    else if (y > x && y > z)
        bigNum = y;
    else
        bigNum = z;
*/