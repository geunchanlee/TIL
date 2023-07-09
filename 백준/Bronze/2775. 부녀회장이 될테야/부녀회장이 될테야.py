T = int(input())
for i in range(T):
    apt = []
    k = int(input())
    n = int(input())
    apt.append([_ for _ in range(1,n+1)])
    for j in range(k):
        floor = []
        cnt = 0
        for l in range(n):
            cnt += apt[j][l]
            floor.append(cnt)
        apt.append(floor)
    print(apt[k][n-1])