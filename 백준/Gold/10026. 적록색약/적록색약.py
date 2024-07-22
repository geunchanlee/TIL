import sys, copy
from collections import deque

input = sys.stdin.readline

N = int(input())
color = [list(input().rstrip()) for _ in range(N)]
color_blind = copy.deepcopy(color)
for i in range(N):
    for j in range(N):
        if color_blind[i][j] == 'R':
            color_blind[i][j] = 'G'

visited = [[False] * N for _ in range(N)]
visited_blind = copy.deepcopy(visited)

def bfs(x, y, mat, visit):
    q = deque()
    q.append([x, y])
    visit[x][y] = True

    while q:
        x, y = q.popleft()
        dx = [1, -1, 0, 0]
        dy = [0, 0, 1, -1]
        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]
            if 0 <= nx < N and 0 <= ny < N:
                if not visit[nx][ny] and mat[x][y] == mat[nx][ny]:
                    visit[nx][ny] = True
                    q.append([nx, ny])

ans = [0, 0]
for i in range(N):
    for j in range(N):
        if not visited[i][j]:
            bfs(i, j, color, visited)
            ans[0] += 1
        if not visited_blind[i][j]:
            bfs(i, j, color_blind, visited_blind)
            ans[1] += 1

print(*ans)