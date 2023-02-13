N = int(input())
a = list(map(int,input().split()))
primeNum = 0
for i in range(N):
    if a[i] < 2:
        pass
    else:
        for j in range(2,a[i]):
            if a[i] % j == 0:
                break
        else:
            primeNum += 1
print(primeNum)