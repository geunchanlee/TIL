#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct book
{
    int number;
    char title[256];
    char author[256];
    char other[256];
};

int main()
{
    FILE *fp = fopen("books.csv", "r");
    if (fp == NULL)
    {
        printf("파일 열기 오류 발생\n");
        return 1;
    }

    char line[512];
    fgets(line, sizeof(line), fp); // 카테고리 정보가 저장되어 있는 첫 번째 줄은 무시합니다.

    struct book *books = NULL;
    int bookCount = 0;
    int maxBooks = 100; // 초기 동적 배열 크기

    books = (struct book *)malloc(maxBooks * sizeof(struct book));
    if (books == NULL)
    {
        printf("메모리 할당 오류 발생\n");
        return 1;
    }

    while (fgets(line, sizeof(line), fp) != NULL)
    {

        char *token = strtok(line, ",");
        books[bookCount].number = atoi(token);

        char *remain = strtok(NULL, "");

        if (remain[0] == '\"')
        {
            // 큰따옴표로 둘러싸인 부분 처리
            token = strtok(remain, "\"");
            strcpy(books[bookCount].title, token);
        }
        else
        {
            // 큰따옴표로 둘러싸인 부분이 없는 경우
            token = strtok(remain, ",");
            strcpy(books[bookCount].title, token);
        }

        remain = strtok(NULL, "");
        token = strtok(remain, "\"");
        strcpy(books[bookCount].author, token);

        remain = strtok(NULL, "");
        token = strtok(remain, "");
        strcpy(books[bookCount].other, token);
        bookCount++;
    }

    fclose(fp);

    for (int i = 0; i < bookCount; i++)
    {
        printf("Num: %d, Title: %s, Author: %s\n", books[i].number, books[i].title, books[i].author);
    }

    free(books);

    return 0;
}
