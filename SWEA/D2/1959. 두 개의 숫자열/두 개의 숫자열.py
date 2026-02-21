T = int(input())

for t in range(1,T+1):
    N, M = map(int, input().split())
    a = [int(i) for i in input().split()]
    b = [int(j) for j in input().split()]

    r = abs(N-M)+1
    result = list()
    if len(a) >= len(b):
        for i in range(r):
            sum = 0
            for j in range(len(b)):
                sum += a[i+j] * b[j]
            result.append(sum)
    else:
        for i in range(r):
            sum = 0
            for j in range(len(a)):
                sum += a[j] * b[i+j]
            result.append(sum)
            
    print(f'#{t} {max(result)}')
