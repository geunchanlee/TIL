import sys
d = {}
N = int(input())
card = [_ for _ in input().split()]
for i in card:
    if i in d:
        d[i] += 1
    else:
        d[i] = 1
M = int(input())
for j in sys.stdin.readline().split():
    if j in d:
        print(d[j], end=' ')
    else:
        print(0, end=' ')