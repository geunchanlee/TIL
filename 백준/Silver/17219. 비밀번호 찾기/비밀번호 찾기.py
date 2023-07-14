import sys
N, M = map(int,sys.stdin.readline().split())
pwDict = {}
for i in range(N):
    a, pw = sys.stdin.readline().split()
    pwDict[a] = pw
for j in range(M):
    q = sys.stdin.readline().rstrip()
    print(pwDict[q])
