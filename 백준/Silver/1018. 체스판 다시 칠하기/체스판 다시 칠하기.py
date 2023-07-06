n, m = map(int,input().split())
board = [input() for _ in range(n)]
paint_cnt = []
for i in range(n-7):
    for j in range(m-7):
        paint = 0
        for row in range(i, i+8):
            for col in range(j, j+8):
                if (row+col)%2 == 1 and board[row][col] == board[i][j]:
                    paint += 1
                elif (row+col)%2 == 0 and board[row][col] != board[i][j]:
                    paint += 1
        paint_cnt.append(min(paint,64-paint))     
print(min(paint_cnt))
