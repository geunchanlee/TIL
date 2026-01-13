#include <stdio.h>
#include <string.h>
#define CRT_SECURE_NO_WARNINGS

int main(void)
{
    char sol[100] = "meet at midnight";
    char ans[100] = "____ __ ________";
    char ch;
    int i;

    while (1)
    {
        printf("\n문자열을 입력하세요: %s", ans);
        printf("글자를 추측하세요: ");
        ch = getchar();
        for (int i = 0; i < strlen(sol); i++)
        {
            if (strcmp(ch, sol[i]) == 0)
            {
                ans[i] = ch;
            }
        }
        printf("%s", ans);
        printf("\n");
    }
    return 0;
}