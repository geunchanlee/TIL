import sys
T = int(input())
r = 0
while r < T:
    R, S = sys.stdin.readline().split()
    R = int(R)
    P = ''
    for i in S:
        P += i*R
    print(P)
    r += 1