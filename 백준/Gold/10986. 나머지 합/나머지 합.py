import sys

N, M = map(int, sys.stdin.readline().split())
numList = [int(_) for _ in sys.stdin.readline().split()]
remainderCnt = [0 for _ in range(M)]

sum = 0
answer = 0

for i in range(N):
    sum += numList[i]
    remainderCnt[sum % M] += 1

answer += remainderCnt[0]
for i in remainderCnt:
    if i == 0:
        continue
    answer += i * (i - 1) // 2

print(answer)
