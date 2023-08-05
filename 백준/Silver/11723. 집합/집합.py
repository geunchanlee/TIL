import sys
M = int(sys.stdin.readline().rstrip())
S = set()
for i in range(M):
    o = sys.stdin.readline().rstrip()
    if o == 'all':
        S = set([1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20])
    elif o == 'empty':
        S = set()
    else:
        o, x = o.split()
        x = int(x)
    if o == 'add':
        if x not in S:
            S.add(x)
    elif o == 'remove':
        if x in S:
            S.remove(x)
    elif o == 'check':
        if x in S:
            print(1)
        else:
            print(0)
    elif o == 'toggle':
        if x in S:
            S.remove(x)
        else:
            S.add(x)