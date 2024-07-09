n = int(input())

x, y = 0, 1
if n < 2:
    print(n)
else:
    for i in range(n-1):
        z = x + y 
        if i % 2 == 0:
            x = z
        else:
            y = z
    print(z)