T = int(input())
for j in range(T):
    a = list(input().split())
    n = float(a[0])
    for i in range(1,len(a)):
        if a[i] == "@":
            n *= 3
        elif a[i] == "%":
            n += 5
        elif a[i] == "#":
            n -= 7
    print(f'{n:.2f}')