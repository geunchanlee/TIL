#include <stdio.h>
#include <stdlib.h>

struct book
{
    int num;
    char title[100];
    char author[100];
    char genre[100];
    char subGenre[100];
    int height;
    char publisher[100];
};

int main()
{
    FILE *fp = fopen("books.csv", "r");
    if (fp == NULL)
    {
        printf("파일 열기 오류 발생\n");
        return 1;
    }

    struct book *books = NULL;
    int cnt = 0;
    int capacity = 0;

    fscanf(fp, "Number,Title,Author,Genre,SubGenre,Height,Publisher\n");

    while (1)
    {
        if (cnt >= capacity)
        {
            capacity += 10;
            books = realloc(books, sizeof(struct book) * capacity);
            if (books == NULL)
            {
                printf("메모리 할당 오류 발생\n");
                fclose(fp);
                return 1;
            }
        }

        // 책데이터 읽어오기 fscanf
        int result = fscanf(fp, "%d,\"%99[^\"]\",\"%99[^\"]\",%99[^,],%99[^,],%d,%99[^\n]\n",
                            &books[cnt].num, books[cnt].title, books[cnt].author, books[cnt].genre, books[cnt].subGenre, &books[cnt].height, books[cnt].publisher);

        printf("fscanf result: %d\n", result);

        if (result == 7)
        {
            printf("Num: %d, Title: %s, Author: %s, Genre: %s, SubGenre: %s, Height: %d, Publisher: %s\n",
                   books[cnt].num, books[cnt].title, books[cnt].author, books[cnt].genre, books[cnt].subGenre, books[cnt].height, books[cnt].publisher);

            cnt++;
        }
        else if (result == EOF)
        {
            break; // Exit the loop when no more data can be read
        }
        else
        {
            printf("Error reading data\n");
            break;
        }
    }

    fclose(fp);
    free(books);
    return 0;
}
