from sys import stdin

N, M = map(int, stdin.readline().split())
basket = [b + 1 for b in range(N)]

for l in range(M):
    i, j = map(int, stdin.readline().split())
    i -= 1
    basket[i:j] = reversed(basket[i:j])
print(*basket)