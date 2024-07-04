#include <stdio.h>
#include <stdlib.h>
#define CRT_SECURE_NO_WARNINGS

int main()
{
    char oFile[100];
    char cFile[100];

    printf("원본 파일 이름: ");
    scanf("%s", &oFile);

    printf("복사 파일 이름: ");
    scanf("%s", &cFile);

    FILE *fp, *fp2 = NULL;
    char file1[100], file2[100];
    int c;
    fp = fopen(file1, "r");
    if (fp == NULL)
    {
        fprintf(stderr, "파일을 열 수 없습니다.\n");
        exit(0);
    }
    while ((c = fgetc(fp) != EOF))
        fputc(c, fp);

    return 0;
}