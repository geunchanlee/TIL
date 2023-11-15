def bfs(start):
    q.put(start)
    visited[start] = True

    while q.empty() == False:
        current = q.get()
        print(current, end=" ")

        for neighbor in a[current]:
            if neighbor != None and visited[neighbor] == False:
                q.put(neighbor)
                visited[neighbor] = True


import queue

q = queue.Queue()
n = 6
a = [
    [1, 2, 3, 4, None],
    [0, 3, None],
    [0, 4, None],
    [0, 1, 4, 5, None],
    [0, 2, 3, 5, None],
    [3, 4, None],
]

for i in range(n):
    visited = [False] * n
    print("bfs(%d) : " % i, end="")
    bfs(i)
    print()
