n = int(input())
t = [int(_) for _ in input().split()]
p = [int(_) for _ in input().split()]

cnt = 0
for i in t:
    cnt += -(-i//p[0])
print(cnt)
print(n//p[1],n%p[1], sep=' ')