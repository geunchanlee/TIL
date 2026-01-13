#include <stdio.h>
#include <string.h>

struct quiz
{
    char question[100];
    char a[100];
    int solution;
};

int main()
{
    struct quiz list[2] = {
        {"임베디드 장치에 가장 적합한 프로그래밍 언어는?",
         "1. Python  2. Java  3.C  4. Javascript", 3},
        {"서로 다른 자료형을 모을 수 있는 구조는?",
         "1. 배열  2. 변수  3. 구조체  4. 포인터", 3}};

    int answer;
    for (int i = 0; i < 2; i++)
    {
        printf("%s\n %s  ", list[i].question, list[i].a);
        scanf("%d", &answer);
        if (answer == list[i].solution)
            printf("맞았습니다.\n");
        else
            printf("틀렸습니다. 정답은 %d\n", list[i].solution);

        printf("\n");
    }
    return 0;
}
