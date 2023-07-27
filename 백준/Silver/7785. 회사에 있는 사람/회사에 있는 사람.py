import sys

n = int(sys.stdin.readline().rstrip())
ans = set()

for i in range(n):
    a, b = sys.stdin.readline().split()
    if a in ans and b == 'leave':
        ans.remove(a)
    elif a not in ans and b == 'enter':
        ans.add(a)
d = sorted(ans, reverse=True)
for j in d:
    print(j)