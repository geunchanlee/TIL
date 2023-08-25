import sys
from collections import deque

input = sys.stdin.readline

dx = [1, -1, 0, 0]
dy = [0, 0, 1, -1]


def BFS(x, y):
    queue = deque()
    queue.append((x, y))

    while queue:
        x, y = queue.popleft()

        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]

            if nx < 0 or nx >= row or ny < 0 or ny >= col:
                continue
            if Maze[nx][ny] == 0:
                continue
            if Maze[nx][ny] == 1:
                Maze[nx][ny] = Maze[x][y] + 1
                queue.append((nx, ny))

    return Maze[row - 1][col - 1]


row, col = map(int, input().split())
Maze = [[int(_) for _ in input().strip()] for _ in range(row)]
print(BFS(0, 0))