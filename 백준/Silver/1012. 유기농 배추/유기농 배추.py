import sys
sys.setrecursionlimit(10000)

def dfs(x, y):
    dx = [1, -1, 0, 0]
    dy = [0, 0, 1, -1]
    for i in range(4):
        nx = x + dx[i]
        ny = y + dy[i]

        if (0 <= nx < N) and (0 <= ny < M):
            if Cabbage[nx][ny] == True:
                Cabbage[nx][ny] = False
                dfs(nx, ny)

for r in range(int(input())):
    M, N, K = map(int,sys.stdin.readline().split())
    Cabbage = [[False for _ in range(M)] for _ in range(N)]
    worm = 0
    
    for c in range(K):
        X, Y = map(int,sys.stdin.readline().split())
        Cabbage[Y][X] = True

    for i in range(N):
        for j in range(M):
            if Cabbage[i][j] > 0:
                dfs(i, j)
                worm += 1
    print(worm)