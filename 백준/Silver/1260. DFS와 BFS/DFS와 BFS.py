import sys
input = sys.stdin.readline

N, M, V = map(int,input().split())
graph = dict()

for node in range(N+1):
    graph[node] = []

for edge in range(M):
    start, end = map(int,input().split())
    graph[start].append(end)
    graph[end].append(start)

for s in graph:
    graph[s].sort()

visited_dfs = [False for _ in range(N+1)]
visited_bfs = [False for _ in range(N+1)]

dfs, bfs = [], []

def DFS(V):
    visited_dfs[V] = True
    dfs.append(V)
    for node in graph[V]:
        if visited_dfs[node] != True:
            DFS(node)

bfs_queue = []
def BFS(V):
    visited_bfs[V] = True
    bfs.append(V)
    bfs_queue.append(V)
    while(bfs_queue):
        v = bfs_queue.pop(0)
        for node in graph[v]:
            if visited_bfs[node] != True:
                visited_bfs[node] = True
                bfs.append(node)
                bfs_queue.append(node)

DFS(V)
BFS(V)
print(*dfs)
print(*bfs)