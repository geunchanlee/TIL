#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define SIZE 512

// 책 정보를 저장하는 구조체입니다.
struct book
{
    int number;
    char title[256];
    char author[256];
    char other[256];
};

/* 자료 형식
1,Fundamentals of Wavelets,"Goswami, Jaideva",tech,signal_processing,228,Wiley
8,"Drunkard's Walk, The","Mlodinow, Leonard",science,mathematics,197,Penguin
8번 의 경우 저자명이 ""로 둘러쌓여있는데 어떻게 처리?
*/

// 파일에서 책 정보를 읽어와서 동적 배열에 저장하는 함수

// 프로그램 메뉴 출력함수
void printMenu()
{
    int select;
    printf("======================================\n");
    printf("1. 도서 번호로 책 찾기\n");
    printf("2. 저자 이름으로 책 찾기\n");
    printf("3. 제목으로 책 찾기\n");
    printf("4. 새로운 책 추가하기\n");
    printf("5. 도서관이 소장한 도서의 수 표시\n");
    printf("프로그램 종료: -1\n");
    printf("======================================\n");
    printf("메뉴 중에서 하나를 선택하세요: ");
}

// 기능들에서 대문자를 소문자로 변환할때 사용할 함수입니다.
void toLowerCase(char input[], int lenth)
{
    // 문자열의 각 문자가 아스키 코드 값으로 90('Z')보다 작으면 대문자이기 때문에 32를 더해 소문자로 만드는 부분입니다.
    for (int i = 0; i < lenth; i++)
    {
        if (input[i] >= 'A' && input[i] <= 'Z')
            input[i] += 32;
    }
}

// 1. 도서 번호로 책 찾기 함수입니다.
void findBookByNumber(struct book *books, int cur_size, int number)
{
    for (int i = 0; i < cur_size; i++)
    {
        if (books[i].number == number)
        {
            printf("찾은 책 정보: %d 제목:%s 저자:%s 나머지:%s\n", books[i].number, books[i].title, books[i].author, books[i].other);
            return;
        }
    }
    printf("%d 번에 해당하는 책을 찾지 못했습니다.\n", number);
}

// 2
void findBookByInfo(struct book *books, int cur_size, const char *findInfo)
{
    // 함수의 입력으로 들어온 저자명을 toLowerCase를 이용해 소문자로 변환해주는 부분입니다.
    char lowerInput[256];
    strcpy(lowerInput, findInfo);
    toLowerCase(lowerInput, strlen(lowerInput));

    int find = 0; // 찾은 책이 여러권일 수 있기 때문에 모두 출력하기 위해 변수를 하나 생성했습니다.

    for (int i = 0; i < cur_size; i++)
    {
        // 함수의 입력과 비교할 책 정보를 toLowerCase함수를 사용해 소문자로 변환해주는 부분입니다.
        char lowerInfo[256];
        strcpy(lowerInfo, books[i].title);
        toLowerCase(lowerInfo, strlen(lowerInfo));

        // 저자명이 일치하는 책을 출력하는 부분입니다.
        if (strstr(lowerInfo, findInfo) != NULL)
        {
            find++; // 일치하는 책을 한 권이라도 찾았을 때 이를 알리기 위해 find변수를 증가시킵니다.
            printf("책 정보 %d: %d,%s\n", find, books[i].number, books[i].title);
        }
    }
    // find 변수가 1이 되지 못했을 때는 저자가 일치하는 책을 찾지 못했다는 것이므로 이 결과를 출력해줍니다.
    if (!find)
        printf("%s 책을 찾지 못했습니다.\n", findInfo);
}

int main()
{
    int cur_size = 0;
    int max_size = SIZE;

    // books.csv 파일 입력을 위한 부분입니다.
    FILE *fp = fopen("books.csv", "r");
    if (fp == NULL)
    {
        printf("파일 열기 오류 발생\n");
        return 1;
    }

    // 책 목록을 위한 구조체의 동적 배열을 생성합니다.
    struct book *books = (struct book *)malloc(sizeof(struct book) * max_size);
    if (books == NULL)
    {
        printf("메모리 할당 오류 발생\n");
        return 1;
    }

    // 파일에서 책 정보를 읽어와서 동적 배열에 저장합니다.
    char line[512];
    fgets(line, sizeof(line), fp); // 카테고리 정보가 저장되어 있는 첫번째 줄은 무시합니다.

    while (fgets(line, sizeof(line), fp) != NULL)
    {
        if (cur_size >= max_size)
        {
            // 동적 배열 크기 확장
            max_size += SIZE;
            books = (struct book *)realloc(books, max_size * sizeof(struct book));
            if (books == NULL)
            {
                printf("메모리 재할당 오류 발생\n");
                exit(1);
            }
        }

        // 첫 ,로 나누어지는 도서 번호 저장
        char *token = strtok(line, ",");
        books[cur_size].number = atoi(token);

        token = strtok(NULL, "");

        // 숫자 이후 제목 파트가 " 로 시작한 경우를 처리합니다.
        if (token[0] == '\"')
        {
            token = strtok(token, "\"");
            strcpy(books[cur_size].title, token);
        }
        else // ""로 제목이 구분되지 않은 경우
        {
            // title 파트의 끝이 "가 아니라 , 일 것이므로 ,를 기준으로 나누어줍니다.
            token = strtok(token, ",");
            strcpy(books[cur_size].title, token);
        }

        token = strtok(NULL, "");

        if (token[0] == '\"')
        {
            token = strtok(token, "\"");
            strcpy(books[cur_size].author, token);
        }
        else if (token[0] == ',' && token[1] != '\"')
        {
            token = strtok(token + 1, ",");
            strcpy(books[cur_size].author, token);
        }
        else if (token[0] == ',')
        {
            token = strtok(token + 1, "\"");
            printf("token: %s\n", token);
            strcpy(books[cur_size].author, token);
        }

        token = strtok(NULL, "");
        if (token != NULL)
        {
            strcpy(books[cur_size].other, token);
        }

        cur_size++;
    }
    // 메뉴에서 입력받은 기능을 실행하는 부분입니다.
    int select = 0;
    while (select != -1)
    {
        printMenu();

        scanf("%d", &select);
        if (select == -1)
        {
            printf("프로그램을 종료합니다.\n");
            break;
        }
        else if (select < 1 || select > 5)
        {
            printf("메뉴를 잘못 선택하셨습니다. 다시 선택해주세요: \n\n");
            continue;
        }
        printf("\n");

        int number = 0;
        char search[100];
        switch (select)
        {
        case 1:
            printf("number: ");
            scanf("%d", &number);
            findBookByNumber(books, cur_size, number);
            break;
        case 2:
            printf("search: ");
            getchar();
            fgets(search, 100, stdin);
            search[strcspn(search, "\n")] = '\0';
            findBookByInfo(books, cur_size, search);
            break;

        case 3:
            printf("search: ");
            getchar();
            fgets(search, 100, stdin);
            search[strcspn(search, "\n")] = '\0';
            findBookByInfo(books, cur_size, search);
            break;
        }

        // 기능 실행 후 돌아갈지 종료할지를 선택하는 부분입니다.
        printf("돌아가기 1, 종료 -1: ");
        scanf("%d", &select);
        if (select != -1)
            continue;
        else
        {
            printf("프로그램을 종료합니다.\n");
            break;
        }
    }
    free(books);

    fclose(fp);

    return 0;
}
