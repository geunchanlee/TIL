import sys

sys.setrecursionlimit(1000000)
input = sys.stdin.readline
N, M = map(int,input().split())
campus = []
for i in range(N):
    line = input().rstrip()
    campus.append(line)

visited_dfs = []
for _ in range(N):
    visited_dfs.append([False for _ in range(M)])

def start(N, M):
    for x in range(N):
        for y in range(M):
            if campus[x][y] == 'I':
                return x, y

x, y = start(N, M)
visited_dfs[x][y] = True
meet = 0
def dfs(x, y):
    global meet
    dx = [1, -1, 0, 0]
    dy = [0, 0, 1, -1]
    for i in range(4):
        nx = x + dx[i]
        ny = y + dy[i]

        if (0 <= nx < N) and (0 <= ny < M):
            if visited_dfs[nx][ny] == False and campus[nx][ny] != 'X':
                if campus[nx][ny] == 'P':
                    meet += 1
                visited_dfs[nx][ny] = True
                dfs(nx, ny)

dfs(x,y)
if meet != 0:
    print(meet)
else:
    print('TT')