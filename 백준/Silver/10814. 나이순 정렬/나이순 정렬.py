import sys

input = sys.stdin.readline
N = int(input())
memeber = {}

for i in range(N):
    age, name = input().split()
    age = int(age)
    if age not in memeber:
        memeber[age] = []
    memeber[age].append(name)

ans = sorted(memeber.items())
for age, name_list in ans:
    for name in name_list:
        print(age, name)