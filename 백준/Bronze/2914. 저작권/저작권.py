import math
A, I = map(int,input().split())

i = 1
while True:
    s = i/A
    if math.ceil(s) == I:
        break
    else:
        i += 1
print(i)