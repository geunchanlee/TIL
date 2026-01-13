# 구간 합 구하기

import sys

input = sys.stdin.readline
N, M = map(int, input().split())
a = []
for _ in range(N):
    b = list(map(int, input().split()))
    a.append(b)

for _ in range(M):
    sum = 0
    x1, y1, x2, y2 = map(int, input().split())
    for i in range(x1 - 1, x2):
        for j in range(y1 - 1, y2):
            sum += a[i][j]
    print(sum)
