A, B = 1, 2
while A != 0 or B != 0:
    A, B = map(int,input().split())
    if A == 0 and B == 0:
        break
    elif A > B:
        print('Yes')
    elif B >= A:
        print('No')
