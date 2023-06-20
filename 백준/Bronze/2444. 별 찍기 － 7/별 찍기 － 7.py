N = int(input())
i = -1
for j in range(2*N-1):
    if j < N:
        i += 2
        print(f'{"*"*i:>{N+i//2}}') 
    else:
        i -= 2
        print(f'{"*"*i:>{N+i//2}}')