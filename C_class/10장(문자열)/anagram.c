#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#define CRT_SECURE_NO_WARNINGS
#define SOL "apple" // 정답 확인용 기호상수

int main()
{
    char word[] = "apple";
    char ans[100];
    char temp;
    int i, r1, r2;

    // 글자 섞기 위한 반복문
    srand(time(NULL));
    for (i = 0; i < strlen(word); i++)
    {
        r1 = rand() % 5;
        r2 = rand() % 5;

        temp = word[r1];
        word[r1] = word[r2];
        word[r2] = temp;
    }

    // 입력이 섞이기 전 정답과 일치할 때 까지 반복해서 입력받음
    do
    {
        printf("%s의 원래 단어를 맞춰보세요: ", word);
        scanf("%s", ans);
    } while (strcmp(ans, SOL) != 0);

    printf("축하합니다.\n");
    return 0;
}