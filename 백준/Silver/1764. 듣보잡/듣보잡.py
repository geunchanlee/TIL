import sys
input = sys.stdin.readline
N, M = map(int, input().split())
d = {input().rstrip() for _ in range(N)}
b = {input().rstrip() for _ in range(M)}
print(len(d&b), *sorted(d&b), sep='\n')