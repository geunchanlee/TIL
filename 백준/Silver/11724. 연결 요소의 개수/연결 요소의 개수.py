import sys
from collections import deque

input = sys.stdin.readline

N, M = map(int,input().split())
graph = dict()
for node in range(N+1):
    graph[node] = []

for edge in range(M):
    u, v = map(int,input().split())
    graph[u].append(v)
    graph[v].append(u)

visited = [False for _ in range(N+1)]
bfs = []

def bfs(v):
    q = deque()
    q.extend(graph[v])
    visited[v] = True
    while q:
        v = q.popleft()
        if not visited[v] and graph[v]:
            visited[v] = True
            q.extend(graph[v])

cnt = 0
for i in range(1, N+1):
    if visited[i] == False:
        bfs(i)
        cnt += 1

print(cnt)