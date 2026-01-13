#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct movie
{
    char title[100];
    float rate;
};

int main(void)
{
    int num;
    float r;
    char type[100];
    struct movie *p;

    printf("영화의 개수: ");
    scanf("%d", &num);
    getchar(); // 줄바꿈 문자 버퍼에서 제거
    p = (struct movie *)malloc(num * sizeof(struct movie));

    if (p == NULL)
    {
        printf("메모리 할당 오류\n");
        exit(1);
    }
    for (int i = 0; i < num; i++)
    {
        printf("영화 제목: ");
        // scanf("%s", type);
        // 중간에 공백 있는 문자열 받고싶으면 get_s이용하기 (mac은 fgtes)
        fgets(type, 100, stdin);
        type[strcspn(type, "\n")] = '\0';
        printf("영화 평점: ");
        scanf("%f", &r);
        getchar(); // 개행문자 제거

        strcpy(p[i].title, type);
        p[i].rate = r;
    }

    printf("\n===============\n");
    for (int i = 0; i < num; i++)
    {
        printf("영화 제목: %s\n", p[i].title);
        printf("영화 평점: %f\n", p[i].rate);
    }

    free(p);
}
