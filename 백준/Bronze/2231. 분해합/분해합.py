N = int(input())
i = 0
while True:
    s = 0
    k = str(i)
    for j in range(len(k)):
        s += int(k[j])

    if i + s == N:
        print(i)
        break
    elif i >= N:
        print(0)
        break
    i += 1
