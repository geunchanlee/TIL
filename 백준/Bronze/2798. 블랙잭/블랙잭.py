N, M = map(int,input().split())
c = sorted([int(c) for c in input().split()])
ans = 0
for i in range(len(c)-2):
    for j in range(i+1,len(c)-1):
        for k in range(i+2, len(c)):
            sum = c[i]+c[j]+c[k]
            if M >= sum and sum > ans:
                ans = sum
print(ans)