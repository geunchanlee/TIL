import sys
a = int(input())
for i in range(a):
    ox = sys.stdin.readline()
    score = 0
    j = 0
    r = 0
    while j < len(ox):
        if ox[j] == 'O':
            r += 1
        else:
            r = 0
        score += r
        j += 1
    print(score)
