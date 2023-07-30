import sys
while True:
    a, b, c = sys.stdin.readline().split()
    b, c  = int(b), int(c)
    if a == '#':
        break
    elif b > 17 or c >=80:
        print(a,'Senior')
    else:
        print(a,'Junior')