import sys

n = set()
for i in range(int(input())):
    n.add(int(sys.stdin.readline().strip()))
for j in sorted(n):
    print(j)
