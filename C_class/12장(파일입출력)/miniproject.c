#include <stdio.h>
#include <stdlib.h>
#define CRT_SECURE_NO_WARNINS
#define KEY 120

// XOR연산으로 암호화, 복호화 하는 프로그램

int main()
{
    int plain[100];
    int ch;
    FILE *fp1, *fp2, *fp3 = NULL;
    fp1 = fopen("plain.txt", "r");
    fp2 = fopen("encryption.bin", "wb");
    if (fp1 == NULL)
    {
        fprintf(stderr, "plain.txt 파일을 열 수 없습니다.");
        exit(1);
    }
    if (fp2 == NULL)
    {
        fprintf(stderr, "encryption.bin 파일을 열 수 없습니다.");
        exit(1);
    }

    int n = 0;
    while ((ch = fgetc(fp1)) != EOF)
    {
        char e = ch ^ KEY;
        fwrite(&e, 1, 1, fp2);
        n++;
    }
    fclose(fp1);
    fclose(fp2);

    // 닫고 다시 열기 가능
    fp2 = fopen("encryption.bin", "rb");
    if (fp2 == NULL)
    {
        fprintf(stderr, "encryption.bin 파일을 열 수 없습니다.");
        exit(1);
    }

    char enc[100];
    fread(enc, 1, n, fp2);
    for (int i = 0; i < 100; i++)
    {
        // int enc = plain[i] ^ KEY;
        printf("%d", plain[i]);
    }

    fclose(fp2);
    fclose(fp3);
    return 0;
}