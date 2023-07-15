N, K = map(int,input().split())
div = []
for i in range(1,N//2+1):
    if N%i == 0:
        div.append(i)
div.append(N)
if len(div) >= K:
    print(sorted(div)[K-1])
else:
    print(0)