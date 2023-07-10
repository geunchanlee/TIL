while True:
    n = sorted([int(i)**2 for i in input().split()])
    if n == [0,0,0]:
        break
    elif sum(n[0:2]) == n[2]:
        print('right')
    else:
        print('wrong')