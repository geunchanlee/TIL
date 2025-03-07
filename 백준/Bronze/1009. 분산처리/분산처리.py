import sys

input = sys.stdin.readline

t = int(input())

for i in range(t):
    a, b = map(int, input().split())
    data = 1
    b = b % 4 + 4
    for j in range(b):
        data = data * a % 10
    if data == 0:
        data += 10
    print(data)
