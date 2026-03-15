import sys

input = sys.stdin.readline
words = [list(input().strip()) for _ in range(5)]
ans = []

for i in range(15):
    for j in range(5):
        if len(words[j]) <= i:
            pass
        else:
            ans.append(words[j][i])

print(*ans, sep="")
