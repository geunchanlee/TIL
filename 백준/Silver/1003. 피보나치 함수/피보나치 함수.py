fib = [[1, 0], [0, 1], [1, 1]]
for i in range(3, 41):
    fib.append([fib[i - 1][0] + fib[i - 2][0], fib[i - 1][1] + fib[i - 2][1]])

t = int(input())
for i in range(t):
    n = int(input())
    print(*fib[n])
