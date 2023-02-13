import sys
o = [1, 1, 2, 2, 2, 8]
n = list(map(int, sys.stdin.readline().split()))
for i in range(6):
    o[i] -= n[i]
for i in o:
    print(i, end=' ')
