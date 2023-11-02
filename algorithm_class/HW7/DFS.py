def dfs(v):
    print(v, end=" ")
    visited[v] = True

    for i in a[v]:
        if visited[i] == False:
            dfs(i)

# None에 대한 오류 처리 어떻게 할 지 생각
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
    print("dfs(%d): " % i, end="")
    dfs(i)
    print()
