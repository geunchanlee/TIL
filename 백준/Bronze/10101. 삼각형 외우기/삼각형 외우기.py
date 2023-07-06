n = [int(input()) for _ in range(3)]
if sum(n) != 180:
    print('Error')
elif sum(n) == 180:
    if n[0] == n[1] == n[2]:
        print('Equilateral')
    elif n[0] == n[1] != n[2] or n[0] != n[1] == n[2] or n[0] == n[2] != n[1]:
        print('Isosceles')
    elif n[0] != n[1] != n[2]:
        print('Scalene')