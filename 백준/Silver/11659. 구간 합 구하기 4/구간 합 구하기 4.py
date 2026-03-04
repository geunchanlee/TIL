import sys

input = sys.stdin.readline

N, M = map(int, input().split())
nums = [int(i) for i in input().split()]

prefix = [0] * (N + 1)

for i in range(1, N+1):
    prefix[i] = prefix[i-1] + nums[i-1]

for i in range(M):
    i, j = map(int,input().split())
    sum = prefix[j] - prefix[i-1]
    print(sum)