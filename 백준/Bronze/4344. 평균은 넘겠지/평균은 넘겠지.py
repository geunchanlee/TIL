C = int(input())
t = 0
while t<C:
    N = list(map(int, input().split()))
    num = N.pop(0)
    a = sum(N)
    r = a/num
    over = 0
    for i in N:
        if i > r:
            over += 1
    print(f"{(over/num)*100:.3f}%")
    t = t+1