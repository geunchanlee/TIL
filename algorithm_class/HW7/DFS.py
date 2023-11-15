def dfs(v):
    if v is None:
        return

    print(v, end=" ")
    visited[v] = True

    # NoneType 에러를 막기 위해 예외 처리 했습니다
    for i in a[v]:
        if i != None:
            if visited[i] == False:
                dfs(i)


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
