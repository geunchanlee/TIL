from sys import stdin

N, M = map(int, stdin.readline().split())
S = set()
L = list()
count = 0

for i in range(N):
    S.add(stdin.readline().strip())
for i in range(M):
    L.append(stdin.readline().strip())

for i in L:
    if i in S:
        count += 1
print(count)
