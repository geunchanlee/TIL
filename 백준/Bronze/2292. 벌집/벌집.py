N = int(input())
i = 1
H = 1
while True:
    if H>= N:
        break
    H += i * 6
    i += 1
print(i)