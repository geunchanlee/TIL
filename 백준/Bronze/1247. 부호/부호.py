import sys
for i in range(3):
    sum = 0
    for i in range(int(sys.stdin.readline().strip())):
        n = int(sys.stdin.readline().strip())
        sum += n
    if sum > 0: print('+')
    elif sum == 0: print(0)
    else: print('-')