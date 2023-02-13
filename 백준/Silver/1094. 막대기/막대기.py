X = int(input())
stick = [64]
while sum(stick) > X:
    stick.sort()
    stick[0] //= 2
    if sum(stick) >= X:
        pass
    else:
        stick.append(stick[0])
print(len(stick))