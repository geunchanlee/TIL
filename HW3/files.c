#include <stdio.h>

typedef struct
{
    int num;
    char title[100];
    char author[100];
    char genre[100];
    char subGenre[100];
    int height;
    char publisher[100];
} Book;

int main()
{
    FILE *file = fopen("books.csv", "r");
    if (file == NULL)
    {
        perror("Error opening file");
        return 1;
    }

    Book book;

    // Assuming the header line is present in the CSV file, so it's read and discarded
    fscanf(file, "Number,Title,Author,Genre,SubGenre,Height,Publisher\n");

    while (fscanf(file, "%d,%99[^,],\"%99[^\"]\",%99[^,],%99[^,],%d,%99[^\n]\n",
                  &book.num, book.title, book.author, book.genre, book.subGenre, &book.height, book.publisher) == 7)
    {
        // Process the data or print it as needed
        printf("Num: %d, Title: %s, Author: %s, Genre: %s, SubGenre: %s, Height: %d, Publisher: %s\n",
               book.num, book.title, book.author, book.genre, book.subGenre, book.height, book.publisher);
    }

    fclose(file);
    return 0;
}
