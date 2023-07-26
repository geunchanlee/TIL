N = int(input())
M = int(input())

p = []
for i in range(N, M + 1):
    for j in range(2, i + 1):
        if j == i:
            p.append(i)
        elif i % j == 0:
            break
if len(p) == 0:
    print(-1)
else:
    print(sum(p))
    print(p[0])
