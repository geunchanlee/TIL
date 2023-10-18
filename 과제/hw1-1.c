#include <stdio.h>
#include <math.h>
#define CRT_SECURE_NO_WARNINGS

int main()
{
    // 입력받는 수를 저장할 변수 x,y와 연산자를 저장할 변수 op 생성
    double x, y;
    char op;

    // 첫 x를 입력받기
    printf("입력: ");
    scanf("%lf", &x);
    printf("\n");

    while (1) // 무한루프로 구성
    {
        // 버퍼에 남은 개행문자를 getchar();로 제거해주고 연산자를 입력받아 op에 저장
        getchar();
        printf("입력: ");
        scanf("%c", &op);
        printf("\n");

        // 연산자가 'q'일 때 계산기를 종료
        if (op == 'q')
            break;

        // 연산자 's'인 경우 두번째 입력이 필요없이 결과값이 나옴
        if (op == 's')
        {
            x = sqrt(x);
            printf("%g\n\n", x);
            continue;
        }


        // 연산자가 아닌 값을 입력하면 연산자를 다시 입력받기 위해 반복문 다시 시작
        if ((op != '+') && (op != '-') && (op != '*') && (op != '/') && (op != 'p'))
        {
            printf("연산자를 입력해야 합니다.\n\n");
            continue;
        }
        else       
        // 연산자를 입력했을 경우 계산할 두번째 수를 입력받아 y에 저장
        {

            printf("입력: ");
            scanf("%lf", &y);
            printf("\n");
        }

        // switch case 조건문으로 각 연산자일때 계산 결과값을 x에 저장
        switch (op)
        {
        case '+':
            x = x + y;
            break;
        case '-':
            x = x - y;
            break;
        case '*':
            x = x * y;
            break;
        case '/':
        // 나누기 연산일 경우 0으로 나누는 경우엔 다시 연산자를 입력받게함
            if (y == 0)
            {
                printf("0으로 나누었습니다.\n\n");
                continue;
            }
            x = x/y;
            break;
        case 'p':
            x = pow(x, y);
            break;
        }

        // 소수점 뒤 출력을 위해 %g로 출력
        printf("%g\n\n", x);
    }
    return 0;
}