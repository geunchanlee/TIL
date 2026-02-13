T = int(input())
arr = [str(i+1) for i in range(T)]

clap = ['3', '6', '9']

for i in range(T):
    if any(x in arr[i] for x in ['3', '6', '9']):
        cnt = 0
        for j in arr[i]:
            if j in ['3','6','9']:
                cnt += 1
            arr[i] = '-'*cnt

print(*arr)
