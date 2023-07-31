import sys

a, b = input().split()
ans = {}
cnt = 0
for i in range(int(a)):
    k, v = sys.stdin.readline().split()
    if k == b:
        b = v
        break
    ans[k] = v
for j in ans:
    if ans.get(j) == b:
        cnt += 1
print(cnt)