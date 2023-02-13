N = int(input())
i = 0
if N%5 == 0:
    print(N//5)
else:
    while N != 3 and N != 6 and N !=9 and N != 12:
        N = N - 5
        i = i + 1
        if N < 3:
            break
    if N < 3:
        print(-1)
    else:
        print(i + N//3)