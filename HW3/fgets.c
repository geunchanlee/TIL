#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define SIZE 128

// 책 정보를 저장하는 구조체입니다.
struct book
{
    int number;
    char info[256];
};

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
        if (input[i] <= 90)
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
            printf("찾은 책 정보: %d,%s\n", books[i].number, books[i].info);
            return;
        }
    }
    printf("%d 번에 해당하는 책을 찾지 못했습니다.\n", number);
}

// 2번과 3번의 책 찾기 함수입니다.
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
        strcpy(lowerInfo, books[i].info);
        toLowerCase(lowerInfo, strlen(lowerInfo));

        // 저자명이 일치하는 책을 출력하는 부분입니다.
        if (strstr(lowerInfo, findInfo) != NULL)
        {
            find++; // 일치하는 책을 한 권이라도 찾았을 때 이를 알리기 위해 find변수를 증가시킵니다.
            printf("책 정보 %d: %d,%s\n", find, books[i].number, books[i].info);
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
    fgets(line, sizeof(line), fp); // 카테고리 정보가 저장되어 있는 첫번째 줄은 읽어만 두고 무시합니다.
    while (fgets(line, sizeof(line), fp) != NULL)
    {
        // 책 정보를 맨 앞의 번호와 나머지 부분으로 나누어 저장합니다.
        // 입력받아온 문자열을 strtok 함수를 이용해 쉼표를 기준으로 나누어 번호와 나머지 부분으로 저장했습니다.
        char *token = strtok(line, ",");
        if (token != NULL)
        {
            books[cur_size].number = atoi(token);

            // 두번째 strtok의 인자를 빈 문자열인 ""로 지정해서 number에 저장하고 남은 모든 부분을 info에 저장했습니다.
            token = strtok(NULL, "");
            if (token != NULL)
            {
                strcpy(books[cur_size].info, token);
                cur_size++;
            }
        }
        // 동적 배열의 크기를 입력에 맞게 조정합니다.
        if (cur_size >= max_size)
        {
            max_size += SIZE;
            books = (struct book *)realloc(books, sizeof(struct book) * max_size);
            if (books == NULL)
            {
                printf("메모리 재할당 오류 발생\n");
                return 1;
            }
        }
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

    fclose(fp);
    free(books);

    return 0;
}
