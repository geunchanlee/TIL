N = int(input())
m = [int(_) for _ in input().split()]
rule, cnt = 0, 0
for i in range(N):
    if m[i] == rule:
        cnt += 1
        if rule < 2: 
            rule += 1
        else: 
            rule = 0
print(cnt)