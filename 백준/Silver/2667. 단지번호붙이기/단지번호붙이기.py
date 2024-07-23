import sys
from collections import deque

input = sys.stdin.readline
N = int(input())
map = [list(map(int,input().rstrip())) for _ in range(N)]
visited = [[False]*N for _ in range(N)]

def bfs(x, y):
    q = deque()
    q.append([x, y])
    visited[x][y] = True
    cnt = 1
    while q:
        x, y = q.popleft()
        dx = [1, -1, 0, 0]
        dy = [0, 0, 1, -1]
        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]
            if (0 <= nx < N) and (0 <= ny < N):
                if not visited[nx][ny] and map[nx][ny] == 1:
                    visited[nx][ny] = True
                    cnt += 1
                    q.append([nx,ny])
    return cnt

complex = []
for i in range(N):
    for j in range(N):
        if map[i][j] == 1 and not visited[i][j]:
            complex.append(bfs(i,j))

complex.sort()
complex.insert(0, len(complex))
print(*complex, sep='\n')