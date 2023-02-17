import sys
N = int(input())
A = set(sys.stdin.readline().split())
M = int(input())
Mn = list(sys.stdin.readline().split())
for i in Mn:
    if i in A:
        print(1)
    else:
        print(0)
