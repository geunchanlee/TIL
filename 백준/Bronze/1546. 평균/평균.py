import sys
N = int(input())
s = list(map(int, sys.stdin.readline().split()))
M = max(s)
new_s = []
for i in range(N):
    new_s.append(s[i]/M*100)
print(sum(new_s)/N)
