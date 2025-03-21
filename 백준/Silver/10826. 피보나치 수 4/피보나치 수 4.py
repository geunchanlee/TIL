fib_list = [0, 1]
n = int(input())
if n > 1:
    for i in range(2, n+1):
        num = (fib_list[i-1] + fib_list[i-2])
        fib_list.append(num)
print(fib_list[n])