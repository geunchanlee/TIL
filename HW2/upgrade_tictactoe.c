#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 3

char board[SIZE][SIZE] = {{' ', ' ', ' '},
                          {' ', ' ', ' '},
                          {' ', ' ', ' '}};

// 게임판을 그려주기 위한 함수입니다.
void printBoard()
{
    char horizontal[20] = "---|---|---\n"; // 보드의 가로선을 그려줄 horizontal 변수입니다.
    for (int i = 0; i < SIZE; i++)
    {
        // 각 반복마다 가로선을 그려주고 마지막에 한번 더 그려서 게임 보드를 완성했습니다.
        printf("%s", horizontal);
        for (int j = 0; j < SIZE; j++)
        {
            printf(" %c ", board[i][j]);
            if (j < 2)
                printf("|");
        }
        printf("\n");
    }
    printf("%s\n", horizontal);
}

// 사용자가 좌표를 입력한 곳이 빈 칸인지 확인하는 함수 isEmpty입니다.
int isEmpty(int x, int y)
{
    if (board[x][y] == ' ')
        return 1;
    else
    {
        printf("빈 칸을 입력해 주세요!\n");
        return 0;
    }
}

// 게임의 승패 여부를 판단할 함수 3개 checkWin, isFullDraw, isEnd입니다.
// 조건연산자를 사용해 승자가 X면 -1을 O면 1을 반환하는 함수를 만들었습니다. 둘다 아니면 0을 반환합니다.
int checkWin()
{
    // 가로, 세로의 경우
    for (int i = 0; i < SIZE; i++)
    {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ')
            return (board[i][0] == 'X') ? -1 : 1;
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ')
            return (board[0][i] == 'X') ? -1 : 1;
    }
    // 대각선의 경우
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ')
        return (board[0][0] == 'X') ? -1 : 1;
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ')
        return (board[0][2] == 'X') ? -1 : 1;

    return 0;
}

// 보드가 꽉 차서 결과가 무승부인지 확인하는 함수입니다.
// 보드를 순회하면서 빈칸이 없을 때 1을 반환하고 있다면 0을 반환합니다.
int isFullDraw()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[i][j] == ' ')
                return 0;
        }
    }
    return 1;
}

// 위 두 함수를 이용해서 게임이 종료되는지를 체크할 isEnd()함수입니다.
// 아래 main함수에서 사용되는 if문에서 이 함수가 0이 아닐때만 체크할 것이므로 각 종료 조건에 0이 아닌 값을 반환했습니다.
int isEnd()
{
    int winner = checkWin();
    if (winner)
    {
        if (winner == -1)
        {
            printf("이겼습니다!\n");
            return 1;
        }
        else
        {
            printf("졌습니다!\n");
            return 2;
        }
    }
    else if (isFullDraw())
    {
        printf("비겼습니다!\n");
        return 3;
    }
    return 0;
}

// 컴퓨터가 둘 수를 정하는 함수 checkTwo, computer입니다.
// 제가 짠 컴퓨터의 승리전략은 우선 컴퓨터가 수를 뒀을 때 게임이 끝나는 3개가 연속이 되는 자리에 최우선으로 두고
// 그런 경우가 없다면 사용자가 둔다면 연속3개를 만들 수 있는 자리를 막는 수를 두게 했습니다.
// 두 가지 경우 모두가 없다면 랜덤한 자리에 수를 놓았습니다.

// 우선 O나 X 가 2칸 연속되는지를 확인하는 checkTwo함수입니다.
// 2개 연속이 있다면 마지막 3번째 칸 번호(0~8)를 리턴하고 없는 경우 -1을 리턴합니다.
int checkTwo(char ox)
{
    // 가로, 세로인 경우 확인
    for (int i = 0; i < SIZE; i++)
    {
        if (board[i][0] == ox && board[i][1] == ox && board[i][2] == ' ')
        {
            return i * SIZE + 2;
        }
        if (board[i][0] == ox && board[i][2] == ox && board[i][1] == ' ')
        {
            return i * SIZE + 1;
        }
        if (board[i][1] == ox && board[i][2] == ox && board[i][0] == ' ')
        {
            return i * SIZE;
        }

        if (board[0][i] == ox && board[1][i] == ox && board[2][i] == ' ')
        {
            return 2 * SIZE + i;
        }
        if (board[0][i] == ox && board[2][i] == ox && board[1][i] == ' ')
        {
            return SIZE + i;
        }
        if (board[1][i] == ox && board[2][i] == ox && board[0][i] == ' ')
        {
            return i;
        }
    }
    // 대각선인 경우 확인
    if (board[0][0] == ox && board[1][1] == ox && board[2][2] == ' ')
        return 8;
    if (board[0][0] == ox && board[2][2] == ox && board[1][1] == ' ')
        return 4;
    if (board[1][1] == ox && board[2][2] == ox && board[0][0] == ' ')
        return 0;
    if (board[0][2] == ox && board[1][1] == ox && board[2][0] == ' ')
        return 6;
    if (board[0][2] == ox && board[2][0] == ox && board[1][1] == ' ')
        return 4;
    if (board[1][1] == ox && board[2][0] == ox && board[0][2] == ' ')
        return 2;

    return -1;
}

// 컴퓨터가 수를 두는 함수입니다.
void computer()
{
    srand(time(NULL));
    // 컴퓨터가 둘 수인 com_x, com_y와 2연속인 경우 칸 번호를 담을 move변수입니다.
    int com_x, com_y;
    int move;

    // 첫줄은 컴퓨터가 끝낼 수 있는 위치를 찾는 경우이고(checkTwo('O')에서 -1이 아닌 칸 번호가 나올 경우)
    // 두번째 줄은 사용자가 끝내는 위치를 막는 경우입니다.
    move = checkTwo('O');
    if (move == -1)
        move = checkTwo('X');

    // 3*3 보드이기 때문에 move에 담은 칸 번호를 이용해 컴퓨터가 두는 수를 만들었습니다.
    com_x = move / SIZE;
    com_y = move % SIZE;

    // move가 0 이상일 때(컴퓨터가 우선순위로 둘 수가 있을 때) 그 위치에 두게 했습니다.
    if (move >= 0)
        board[com_x][com_y] = 'O';

    // 우선순위 수가 없는 경우엔 랜덤한 자리에 수를 두게 했습니다. do-while문을 이용해 랜덤한 자리가 빈 칸일 때 까지 반복시켰습니다.
    else
    {
        do
        {
            move = rand() % (SIZE * SIZE);
            com_x = move / SIZE;
            com_y = move % SIZE;
        } while (board[com_x][com_y] != ' ');
        board[com_x][com_y] = 'O';
    }
}

int main()
{
    int x, y;

    while (1)
    {
        printf("플레이어(X)가 둘 차례입니다.\n");
        printf("(x, y) 좌표: ");
        scanf("%d %d", &x, &y);

        // 입력받은 좌표가 빈칸인지 확인하고 빈칸이면 둡니다.
        if (isEmpty(x, y))
            board[x][y] = 'X';
        else
        {
            continue;
        }
        // 수를 두면 보드를 그려주고 게임이 끝나는지 확인합니다.
        // isEnd가 0이 아니면 if문 안의 문장이 실행되어 게임 결과가 출력되고 break로 반복문도 종료됩니다.
        printBoard();
        if (isEnd())
            break;

        // 컴퓨터 차례에도 수를 두고 보드를 그린 뒤 게임이 끝나는지 확인합니다.
        printf("컴퓨터(O)가 둘 차례입니다. \n");
        computer();
        printBoard();
        if (isEnd())
            break;
    }
    return 0;
}
