#include <stdio.h>
#define CRT_SECURE_NO_WARNINGS

char board[3][3] = {{' ', ' ', ' '},
                    {' ', ' ', ' '},
                    {' ', ' ', ' '}};

void printBoard()
{
    char horizontal[20] = "---|---|---\n"; // 보드의 가로선을 그려줄 horizontal 변수입니다.
    for (int i = 0; i < 3; i++)
    {
        // 각 반복마다 가로선을 그려주고 마지막에 한번 더 그려서 게임 보드를 완성했습니다.
        printf("%s", horizontal);
        for (int j = 0; j < 3; j++)
        {
            printf(" %c ", board[i][j]);
            if (j < 2)
                printf("|");
        }
        printf("\n");
    }
    printf("%s\n", horizontal);
}

int checkWin()
{
    for (int i = 0; i < 3; i++)
    {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ')
            return 1; // 가로로 같은 글자가 있는 경우
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ')
            return 1; // 세로로 같은 글자가 있는 경우
    }
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ')
        return 1; // 대각선으로 같은 글자가 있는 경우
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ')
        return 1; // 대각선으로 같은 글자가 있는 경우

    return 0;
}

int isDraw()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3 j++)
        {
            if (board[i][j] == ' ')
                return 0;
        }
    }
    return 1;
}

// 사용자가 수를 두기 위해 입력한 곳이 빈 칸인지 확인하는 함수 isEmpty입니다.
int isEmpty(int x, int y)
{
    if (board[x][y] == ' ')
        return 1;
    else
    {
        printf("빈 칸을 입력해 주세요");
        return 0;
    }
}

int main()
{
    int isPlayerTurn = 1;
}
