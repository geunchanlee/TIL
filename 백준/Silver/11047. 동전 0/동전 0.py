import sys

input = sys.stdin.readline
N, K = map(int, input().split())
coin = [int(input().rstrip()) for _ in range(N)]
coin.sort(reverse=True)
cnt = 0
while K > 0:
    for i in coin:
        if i > K:
            pass
        else:
            cnt += K // i
            K = K % i
            break
print(cnt)