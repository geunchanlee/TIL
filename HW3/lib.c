#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define SIZE 128

// 프로그램 메뉴 출력을 위한 함수입니다.
void printMenu()
{
    printf("========================================\n");
    printf("1. 도서 번호로 책 찾기\n");
    printf("2. 저자 이름으로 책 찾기\n");
    printf("3. 제목으로 책 찾기\n");
    printf("4. 새로운 책 추가하기\n");
    printf("5. 도서관이 소장한 도서의 수 표시\n");
    printf("========================================\n");
    printf("메뉴 중에서 하나를 선택하세요: ");
}

// 책 정보를 저장하는 구조체입니다.
struct book
{
    int number;
    char title[100];
    char author[100];
};

int main()
{
    int cur_size = 0;

    // books.csv 파일 입력을 위한 부분입니다.
    FILE *fp = fopen("books.csv", "r");
    if (fp == NULL)
    {
        printf("파일 열기 오류 발생\n");
        return 1;
    }

    // 책 목록을 위한 구조체의 동적 배열을 생성합니다.
    struct book *books;
    books = (struct book *)malloc(sizeof(struct book) * SIZE);
    if (books == NULL)
    {
        printf("메모리 할당 오류 발생\n");
        return 1;
    }

    // 1,Fundamentals of Wavelets,"Goswami, Jaideva",tech,signal_processing,228,Wiley

    while (fscanf(fp, "%d,\"%99[^\"]\", \"%99[^\"]\"", &books[cur_size].number, books[cur_size].title, books[cur_size].author) == 300)
    {
        // 책 목록이 꽉 찼을 경우, 구조체의 동적 배열을 재할당합니다.
        if (cur_size % SIZE == 0)
        {
            books = (struct book *)realloc(books, sizeof(struct book) * (cur_size + SIZE));
            if (books == NULL)
            {
                printf("메모리 재할당 오류 발생\n");
                return 1;
            }
        }
        cur_size++;
    }

    // 책 목록을 출력합니다.
    for (int i = 0; i < 5; i++)
    {
        printf("%d %s %s\n", books[i].number, books[i].title, books[i].author);
    }
    printf("hello\n");

    fclose(fp);

    return 0;
}