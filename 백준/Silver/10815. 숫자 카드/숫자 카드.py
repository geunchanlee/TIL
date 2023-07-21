import sys
input = sys.stdin.readline
N = int(input().rstrip())
card = {int(_) for _ in input().split()}
M = int(input().rstrip())
find = [int(_) for _ in input().split()]
ans = []
for i in find:
    if i in card:
        ans.append(1)
    else:
        ans.append(0)
print(*ans)