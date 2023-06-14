N, M = map(int, input().split())
N_list = [b + 1 for b in range(N)]
for i in range(M):
    i, j = map(int, input().split())
    i, j = i - 1, j - 1
    N_list[i], N_list[j] = N_list[j], N_list[i]
    
print(*N_list)
