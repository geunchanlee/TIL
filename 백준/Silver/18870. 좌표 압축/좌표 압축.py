import sys
N = int(input())
x = [int(_) for _ in input().split()]
xsort = sorted(x)
ans = {}
cnt = 0
for i in xsort:
    if i not in ans:
        ans[i] = cnt
        cnt += 1
for j in x:
    print(ans[j], end=' ')