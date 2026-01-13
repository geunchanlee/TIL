#include <stdio.h>
void FtoC(float F); // 함수 원형 작성

int main()
{
    FtoC(32);
    return 0;
}

void FtoC(float F)
{
    float C = (F - 32) * 5 / 9;
    printf("화씨온도 %f은 섭씨온도 %f에 해당한다.\n", F, C);
}