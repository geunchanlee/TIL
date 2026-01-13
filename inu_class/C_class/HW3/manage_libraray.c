#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define SIZE 128

// 책 정보를 저장하는 구조체입니다.
struct book
{
    int number;
    char title[256];
    char author[256];
    char others[256];
};

// 프로그램 메뉴 출력함수입니다.
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
            printf("찾았습니다!\n");
            printf("도서번호: %d 제목: %s 저자: %s 나머지: %s\n", books[i].number, books[i].title, books[i].author, books[i].others);
            return;
        }
    }
    printf("%d번에 해당하는 책을 찾지 못했습니다.\n", number);
}

// 2,3번 저자 이름과 책 제목으로 찾기 함수입니다.
void findBookBySearch(struct book *books, int cur_size, const char *findInfo, int isAuthor)
{
    // 함수의 입력으로 들어온 입력을 toLowerCase를 이용해 소문자로 변환해주는 부분입니다.
    char lowerInput[256];
    strcpy(lowerInput, findInfo);
    toLowerCase(lowerInput, strlen(lowerInput));

    int find = 0; // 찾은 책이 여러권일 수 있기 때문에 모두 출력하기 위해 변수를 하나 생성했습니다.

    // 함수의 입력과 비교할 책 정보를 toLowerCase함수를 사용해 소문자로 변환해주는 부분입니다.
    for (int i = 0; i < cur_size; i++)
    {
        char lowerInfo[256];

        // isAuthor 가 1일땐 저자 이름으로 찾는 기능으로, 아닐땐 책 제목으로 찾는 기능으로 사용됩니다.
        if (isAuthor)
            strcpy(lowerInfo, books[i].author);
        else
            strcpy(lowerInfo, books[i].title);
        toLowerCase(lowerInfo, strlen(lowerInfo));

        // 검색과 일치하는 책을 출력하는 부분입니다.
        if (strstr(lowerInfo, findInfo) != NULL)
        {
            if (!find)
                printf("찾았습니다!\n");
            find++; // 일치하는 책을 한 권이라도 찾았을 때 이를 알리기 위해 find변수를 증가시킵니다.
            printf("정보%d, 도서번호: %d 제목: %s 저자: %s 기타: %s", find, books[i].number, books[i].title, books[i].author, books[i].others);
        }
    }
    // find 변수가 1이 되지 못했을 때는 일치하는 책을 찾지 못했다는 것이므로 결과를 출력해줍니다.
    if (!find)
    {
        if (isAuthor == 1)
            printf("%s작가의 책을 찾지 못했습니다.\n", findInfo);
        else
            printf("검색어(%s)를 포함한 책을 찾지 못했습니다.\n", findInfo);
    }
}

// 4. 새로운 책 추가하기 함수입니다.
void addNewBook(struct book *books, int cur_size, int max_size)
{
    // books.csv 파일을 다시 열어서 새로운 책을 추가하는 부분입니다.
    FILE *fp = fopen("books.csv", "a");
    if (fp == NULL)
    {
        printf("파일 열기 오류 발생\n");
        return;
    }

    // 새로운 책의 정보를 입력받는 부분입니다.
    int number = cur_size + 1;
    char title[256];
    char author[256];
    char others[256];
    printf("추가할 책의 정보를 입력하세요.\n");
    printf("제목: ");
    getchar();
    fgets(title, 256, stdin);
    title[strcspn(title, "\n")] = '\0';
    printf("저자: ");
    fgets(author, 256, stdin);
    author[strcspn(author, "\n")] = '\0';
    printf("기타: ");
    fgets(others, 256, stdin);
    others[strcspn(others, "\n")] = '\0';

    // 입력받은 정보를 배열에 추가하는 부분입니다.
    if (cur_size >= max_size)
    {
        // 동적 배열 크기를 realloc으로 늘리는 부분입니다.
        max_size += SIZE;
        books = (struct book *)realloc(books, max_size * sizeof(struct book));
        if (books == NULL)
        {
            printf("메모리 재할당 오류 발생\n");
            exit(1);
        }
    }

    // 새로운 책의 정보를 배열에 저장합니다.
    books[cur_size].number = number;
    strcpy(books[cur_size].title, title);
    strcpy(books[cur_size].author, author);
    strcpy(books[cur_size].others, others);
    cur_size++;

    // 입력받은 정보를 파일에 쓰는 부분입니다.
    fprintf(fp, "%d,%s,%s,%s\n", number, title, author, others);
    fclose(fp);
}

// 5. 도서관이 소장한 도서의 수 표시 함수입니다.
int bookCount(struct book *books)
{
    int count = 0;
    while (books[count].number != 0)
        count++;
    return count;
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
    char line[SIZE];
    fgets(line, sizeof(line), fp); // 카테고리 정보가 저장되어 있는 0번째 줄은 무시합니다.

    while (fgets(line, sizeof(line), fp) != NULL)
    {
        if (cur_size >= max_size)
        {
            // 동적 배열 크기를 realloc으로 늘리는 부분입니다.
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
        else // ""로 제목이 둘러쌓이지 않은 경우
        {
            // title 파트의 끝이 "가 아니라 ,일 것이므로 ,를 기준으로 나누어줍니다.
            token = strtok(token, ",");
            strcpy(books[cur_size].title, token);
        }
        token = strtok(NULL, ""); // title을 처리하고 남은 문자열을 token에 저장합니다.

        // title을 처리하고 바로 " 가 나타나면 그대로 구분해서 books.author에 저장합니다.
        if (token[0] == '\"')
        {
            token = strtok(token, "\"");
            strcpy(books[cur_size].author, token);
        }
        // "로 저자명이 감싸져있지 않은 경우입니다.
        // 저자 앞에 ,가 나오게 되므로 token +1 부터 시작해서(맨 앞의 ,를 무시하기 위해) ,를 기준으로 나누어줍니다.
        else if (token[0] == ',' && token[1] != '\"')
        {
            token = strtok(token + 1, ",");
            strcpy(books[cur_size].author, token);
        }
        // ,로 시작할 경우 ,를 읽어들이지 않기 위해 token + 1에서부터 시작해 "를 기준으로 나누어줍니다.
        else if (token[0] == ',')
        {
            token = strtok(token + 1, "\"");
            strcpy(books[cur_size].author, token);
        }
        // title, author를 처리하고 남은 부분은 books.others에 저장합니다.
        token = strtok(NULL, "");
        if (token != NULL)
            strcpy(books[cur_size].others, token);
        cur_size++;
    }

    // 파일 입력을 끝내고 프로그램 기능 부분입니다.
    int select = 0;
    while (select != -1)
    {
        printMenu();
        // 메뉴를 선택하는 부분입니다. 잘못된 입력이 들어오면 다시 선택하도록 했습니다.
        scanf("%d", &select);
        printf("\n");
        if (select == -1)
        {
            printf("프로그램을 종료합니다.\n");
            break;
        }
        else if (select < 1 || select > 5)
        {
            printf("메뉴를 잘못 선택하셨습니다. 다시 선택해주세요: ");
            scanf("%d", &select);
        }

        int number = 0;
        char search[100];

        // 선택한 메뉴를 실행하는 부분입니다.
        switch (select)
        {
        case 1:
            printf("도서 번호로 찾기: ");
            scanf("%d", &number);
            findBookByNumber(books, cur_size, number);
            break;
        case 2:
            printf("저자 이름으로 찾기: ");
            getchar();
            fgets(search, 100, stdin);
            search[strcspn(search, "\n")] = '\0';
            findBookBySearch(books, cur_size, search, 1);
            break;

        case 3:
            printf("제목으로 책 찾기: ");
            getchar();
            fgets(search, 100, stdin);
            search[strcspn(search, "\n")] = '\0';
            findBookBySearch(books, cur_size, search, 0);
            break;
        case 4:
            addNewBook(books, cur_size, max_size);
            cur_size++;
            break;
        case 5:
            printf("도서관 장서 수는 %d권입니다.\n", bookCount(books));
            break;
        }

        // 기능 실행 후 돌아갈지 종료할지를 선택하는 부분입니다.
        select = 0;
        printf("메뉴로 돌아가기 1  종료 -1: ");
        scanf("%d", &select);
        if (select == -1)
        {
            printf("프로그램을 종료합니다.\n");
            break;
        }
        else if (select == 1)
        {
            continue;
        }
        else
        {
            printf("잘못된 입력입니다. 프로그램을 종료합니다.\n");
            break;
        }
    }

    // 사용한 메모리 반환하고 파일 닫아줍니다.
    free(books);
    fclose(fp);

    return 0;
}
