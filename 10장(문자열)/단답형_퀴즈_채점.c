#include <stdio.h>
#include <string.h>

int main()
{
    char a[] = "C";
    char ans[99] = ""; // ans[]안에 숫자를 써주지 않으면 길이가 1이 된다.
    while (1)
    {
        printf("임베디드 장치에 가장 많이 사용되는 언어는? ");
        scanf("%s", ans);
        if (strcmp(a, ans) == 0) // strcmp 가 0이면 같음
        {
            printf("맞았습니다!\n");
            break;
        }
    }
    return 0;
}