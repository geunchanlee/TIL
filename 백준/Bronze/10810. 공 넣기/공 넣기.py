N, M = map(int, input().split())
basket = [0 for n in range(N)]
for m in range(M):
    i, j, k = map(int, input().split())
    basket[i - 1 : j] = [k for l in range(j - i + 1)]
print(*basket)
