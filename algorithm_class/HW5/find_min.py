from collections import deque
import sys

input = sys.stdin.readline
N, L = map(int, input().split())
A = list(map(int, input().split()))
q = deque()
ans = []
for i in range(N):
    while q and q[-1][0] > A[i]:
        q.pop()
    while q and q[0][1] < i - L + 1:
        q.popleft()
    q.append((A[i], i))
    print(q[0][0], end=" ")
