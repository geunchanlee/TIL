import sys
input = sys.stdin.readline
N = int(input().rstrip())
card = {int(_) for _ in input().split()}
M = int(input().rstrip())
ans = []
for i in [int(_) for _ in input().split()]:
    if i in card:
        ans.append(1)
    else:
        ans.append(0)
print(*ans)