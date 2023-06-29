for t in range(int(input())):
    C = int(input())
    cent = [25,10,5,1]
    coin = []
    for i in cent:
        coin.append(C//i)
        C %= i
    print(*coin)