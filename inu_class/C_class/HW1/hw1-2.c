#include <stdio.h>
#define CRT_SECURE_NO_WARNINGS

int main()
{
    // 크기를 입력받아 3 이상이 아니면 프로그램 종료
    int n;
    printf("크기를 입력하세요: ");
    scanf("%d", &n);

    if (n < 3)
    {
        printf("3 이상의 정수를 입력하세요");
    }
    else
    {
        // 줄마다 문자 앞에 올 공백의 개수 frontBlank와 줄마다 *,&출력 결정을 위해 줄번호를 저장할 lineNum변수 선언
        // 각 줄의 좌우 문자와 가운대 공백의 개수를 저장할 변수 mid와 반복문을 위한 변수 i,j 선언
        int frontBlank, lineNum = 0;
        int mid, i, j;

        // mid는 첫줄 별의 개수인 n부터 3이하까지 -2씩 줄면서 반복
        // 두 개의 for문이 겹치는 부분인 도형 가운데 부분은 첫번째 for문에서 출력되지 않음
        for (mid = n; mid > 2; mid -= 2)
        {
            // 각 줄에서 먼저 나와야 할 공백을 출력
            for (j = 0; j <= frontBlank; j++)
                printf(" ");

            // 각 줄에서 공백 이후 출력될 부분
            for (i = 0; i < mid; i++)
            {
                // i == 0은 출력의 왼쪽문자, mid == n은 첫번째 줄일 경우 전부 출력하기 위한 부분, i == mid-1은 오른쪽 부분
                if (i == 0 || mid == n || i == mid - 1)
                {
                    // 줄번호가 홀수일 때는 *를, 짝수면 &를 출력한다
                    if (lineNum % 2 == 0)
                        printf("*");
                    else
                        printf("&");
                }
                // 문자가 출력되지 않는 경우엔 공백을 출력
                else
                    printf(" ");
            }
            // 한 줄 출력이 끝나면 줄바꿈 해주고 앞에 들어갈 공백 frontBlank와 줄번호 lineNum을 1씩 증가시킨다
            printf("\n");
            frontBlank++;
            lineNum++;
        }

        // 도형의 하단부분을 출력하기 위한 for문
        // 위 for문에서 줄어든 mid를 가지고 와서 n이상이 될 때까지 +2씩 하면서 반복
        for (; mid <= n; mid += 2)
        {
            // 각 줄 앞부분의 공백 출력
            for (j = 0; j <= frontBlank; j++)
                printf(" ");

            // 위 for문과 동일하게 구성
            for (i = 0; i < mid; i++)
            {
                if (i == 0 || mid == n || i == mid - 1)
                {
                    if (lineNum % 2 == 0)
                        printf("*");
                    else
                        printf("&");
                }
                else
                    printf(" ");
            }
            // 위와 같지만 여기서부터는 줄이 내려갈때마다 앞 공백이 한칸씩 줄어듬
            printf("\n");
            frontBlank--;
            lineNum++;
        }
    }
}