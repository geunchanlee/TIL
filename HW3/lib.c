#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define SIZE 128

struct book
{
    int number;
    char title[100];
    char author[100];
};

int main()
{
    int cur_size = SIZE;

    // 파일 입출력을 위한 부분입니다.
    FILE *fp;
    fp = fopen("books.csv", "r");
    if (fp == NULL)
    {
        printf("파일 열기 오류 발생\n");
        return 1;
    }

    // 책 목록을 구조체의 동적 배열을 생성합니다.
    struct book *books;
    books = (struct book *)malloc(sizeof(struct book) * SIZE);
    if (books == NULL)
    {
        printf("메모리 할당 오류 발생\n");
        return 1;
    }

    char line[256];
    while (fgets(line, sizeof(line), fp))
    {
        // 책의 정보를 입력받습니다.
        char *ptr = strtok(line, ",");
        books[cur_size - SIZE].number = atoi(ptr);
        ptr = strtok(NULL, ",");
        strcpy(books[cur_size - SIZE].title, ptr);
        ptr = strtok(NULL, "");
        strcpy(books[cur_size - SIZE].author, ptr);

        // 책 목록의 크기를 늘립니다.
        cur_size++;
        books = (struct book *)realloc(books, sizeof(struct book) * cur_size);
        if (books == NULL)
        {
            printf("메모리 할당 오류 발생\n");
            return 1;
        }
    }

    // 책 목록을 출력합니다.
    for (int i = 0; i < cur_size - SIZE; i++)
    {
        printf("%d %s %s\n", books[i].number, books[i].title, books[i].author);
    }

    fclose(fp);

    return 0;
}