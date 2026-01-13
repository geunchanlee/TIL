#include <stdio.h>
#include <string.h>

// 단어를 역순으로 출력하는 1번 함수 wordReverse입니다
void wordReverse(char input[], int start, int end)
{
    // 재귀를 종료할 조건입니다.
    if (start >= end)
        return;

    // 현재 선택된 단어의 끝 지점을 저장할 변수를 생성합니다.
    int wordEnd = start;

    // 중간에 공백, NULL문자가 나올 때까지 wordEnd를 증가시켜서 현재 단어의 끝을 찾습니다.
    while (input[wordEnd] != ' ' && input[wordEnd] != '\0')
        wordEnd++;

    // 뒷 단어부터 출력하기 위해 재귀를 이용합니다.
    wordReverse(input, wordEnd + 1, end);

    // 현재 단어 출력
    for (int i = start; i < wordEnd; i++)
        printf("%c", input[i]);

    // 시작점이 문장 맨 마지막에 있는 NULL문자가 아니면(첫 단어가 아니라면)
    // 다음 단어를 출력할 때 공백을 출력해줍니다.
    if (input[start] != '\0')
        printf(" ");
}

// 단어를 사전 순으로 출력하는 2번째 함수 wordSort입니다.
void wordSort(char input[])
{
    // 단어 최대 10개 이하면서 길이 100 이하의 문장을 입력받기 위한 2차원 배열입니다.
    char words[10][100];
    int wordNum = 0;

    // strtok를 사용해 2차원 배열에 각 단어를 " "를 기준으로 구분해 넣었습니다.
    char *ptr = strtok(input, " ");
    while (ptr != NULL && wordNum < 10)
    {
        strcpy(words[wordNum], ptr);
        wordNum++;
        ptr = strtok(NULL, " ");
    }

    // 주어진 단어들을 strcpy를 이용해서 알파벳 순으로 버블정렬합니다
    for (int i = 0; i < wordNum - 1; i++)
    {
        for (int j = 0; j < wordNum - i - 1; j++)
        {
            if (strcmp(words[j], words[j + 1]) > 0)
            {
                char temp[100];
                strcpy(temp, words[j]);
                strcpy(words[j], words[j + 1]);
                strcpy(words[j + 1], temp);
            }
        }
    }

    for (int i = 0; i < wordNum; i++)
        printf("%s ", words[i]);
    printf("\n");
}

int main()
{
    char input[100];
    int wordNum = 0;

    // mac os 환경에서 진행했습니다. fgets로 문장을 입력받았고 이에 따라오는 개행문자를 처리했습니다.
    printf("문장을 입력하세요: ");
    fgets(input, 100, stdin);
    input[strcspn(input, "\n")] = '\0';

    wordReverse(input, 0, strlen(input));
    printf("\n");
    wordSort(input);

    return 0;
}