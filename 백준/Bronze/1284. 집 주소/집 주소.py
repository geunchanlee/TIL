while True:
    N = input()
    ans = 1
    if N == '0':
        break
    else:
        for i in N:
            if i == '1':
                ans += 3
            elif i == '0':
                ans += 5
            else:
                ans += 4
    print(ans)