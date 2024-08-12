import sys
input = sys.stdin.readline

a = [0, 1, 2, 4, 7]

t = int(input())
for i in range(5,12):
    ans = 0
    for j in range(1,4):
        ans += a[i-j]
    a.append(ans)

for k in range(t):
    n = int(input())
    print(a[n])