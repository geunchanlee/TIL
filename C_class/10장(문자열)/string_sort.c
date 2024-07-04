#include <stdio.h>
#include <string.h>
#define CRT_SECURE_NO_WARNINGS
#define SIZE 6

int main()
{
    int i, k;
    char temp[100];
    char fruits[SIZE][20] = {
        "pineapple",
        "banana",
        "apple",
        "tomato",
        "pear",
        "avocado"};

    for (i = 0; i < SIZE - 1; i++)
    {
        for (k = i; k < SIZE; k++)
        {
            if (strcmp(fruits[i], fruits[k]) > 0)
            {
                strcpy(temp, fruits[k]);
                strcpy(fruits[k], fruits[i]);
                strcpy(fruits[i], temp);
            }
        }
    }
    for (i = 0; i < SIZE; i++)
    {
        printf("%s\n", fruits[i]);
    }
}