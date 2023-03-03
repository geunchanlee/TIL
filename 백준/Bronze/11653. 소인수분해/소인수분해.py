def isPrime(x):
    for i in range(2, x):
        if x % i == 0:
            return False
    return True

N = int(input())
while True:
    if N == 1:
        break
    if isPrime(N) == True:
        print(N)
        break
    for i in range(2, N):
        if N % i == 0 and isPrime(i) == True:
            N = N//i
            print(i)
            break
