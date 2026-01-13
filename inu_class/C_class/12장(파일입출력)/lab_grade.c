#include <stdio.h>
#include <stdlib.h>
#define CRT_SECURE_NO_WARNINGS

int main()
{
    FILE *fp = NULL;

    int id, grade;
    char name[100];
    char c;

    fp = fopen("grade.txt", "w");
    if (fp == NULL)
    {
        fprintf(stderr, "파일을 열 수 없습니다.\n");
        exit(1);
    }
    do
    {
        printf("학번: ");
        scanf("%d", &id);
        printf("이름: ");
        scanf("%s", name);
        printf("성적: ");
        scanf("%d", &grade);

        fprintf(fp, "%d %s %d\n", id, name, grade);

        printf("데이터 추가를 계속? (y/n): ");
        c = getchar();
    } while (c != 'n');

    fclose(fp);
    return 0;
}