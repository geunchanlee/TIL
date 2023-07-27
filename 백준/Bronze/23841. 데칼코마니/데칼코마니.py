import sys

input = sys.stdin.readline
N, M = map(int, input().split())
ans = []
for i in range(N):
    draw = [_ for _ in input().rstrip()]
    for j in range(M):
        if draw[j] != ".":
            draw[M - (j + 1)] = draw[j]
    ans.append(draw)
for i in range(N):
    print(''.join(ans[i]))
