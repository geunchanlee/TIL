import sys
from collections import deque

input = sys.stdin.readline

N = int(input()) 
c = int(input())
graph = dict() 

for node in range(1,N+1):
    graph[node] = []

for edge in range(c):
    start, end = map(int,input().split())
    graph[start].append(end)
    graph[end].append(start)

def bfs(start, graph):
    queue = deque([start])
    visited = set([start])

    while queue:
        curr_node = queue.popleft()
        for next_node in graph[curr_node]:
            if next_node not in visited:
                visited.add(next_node)
                queue.append(next_node)
    return len(visited)-1

print(bfs(1,graph))