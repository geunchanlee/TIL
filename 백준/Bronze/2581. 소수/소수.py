N, M = int(input()), int(input())
# 에라토스테네스의 체 사용
P = [True] * (M+1)
P[1] = False
for i in range(2, int(M**0.5) + 1):
    if P[i] == True:
        for j in range(i + i, M + 1, i):
            P[j] = False

ans = [i for i in range(N, M + 1) if P[i] == True]

if len(ans) == 0:
    print(-1)
else:
    print(sum(ans))
    print(ans[0])