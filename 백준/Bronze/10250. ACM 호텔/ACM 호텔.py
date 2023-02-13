T = int(input())
for i in range(T):
    H, W, N = map(int, input().split())
    X = 1
    while N > H:
        N = N - H
        X = X + 1
    print((N*100)+X)