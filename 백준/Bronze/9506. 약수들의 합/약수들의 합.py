import sys

def getPerfectNum(n):
    isDiv = []
    for i in range(1,n // 2 + 1):
        if n % i == 0:
            isDiv.append(i)
    if sum(isDiv) == n:
        print(n,'=', end=' ')
        print(*isDiv, sep = ' + ')
    else:
        print(f'{n} is NOT perfect.')
while True:
    n = int(sys.stdin.readline().strip())
    if n == -1:
        break
    getPerfectNum(n)