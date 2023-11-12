#include <stdio.h>
#include <string.h>
#define CRT_SECURE_NO_WARNINGS
#define key 120

int main()
{
    char str[100];
    char enc[100];
    char dec[100];
    printf("문자열 입력: ");
    scanf("%s", str);

    for (int i = 0; i < strlen(str); i++)
    {
        enc[i] = str[i] ^ key;
    }
    printf("암호화된 문장: %s", enc);
}
