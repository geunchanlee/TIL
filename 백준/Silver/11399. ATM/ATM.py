n = int(input())
t = [int(_) for _ in input().split()]
ans = 0
for i in range(1,n+1):
    ans += sum(sorted(t)[0:i])
print(ans)