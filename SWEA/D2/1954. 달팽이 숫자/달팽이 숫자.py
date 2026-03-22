T = int(input())

for test_case in range(1, T + 1):
    N = int(input())
    snail = [[0] * N for _ in range(N)]

    # x, y, d(direction)
    x, y, d = 0, 0, 0

    # 우하좌상
    dx = [1, 0, -1, 0]
    dy = [0, 1, 0, -1]

    for num in range(1, N * N + 1):
        snail[y][x] = num
        nx = x + dx[d]
        ny = y + dy[d]

        if 0 <= nx < N and 0 <= ny < N and snail[ny][nx] == 0:
            x, y = nx, ny
        else:
            d = (d + 1) % 4
            x += dx[d]
            y += dy[d]

    print(f'#{test_case}')
    for i in range(N):
        print(*snail[i])
