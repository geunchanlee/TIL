N = int(input())
t = -1
p = []
for i in range(N):
    A, B = map(int,input().split())
    if A - B < 0:
        p.append(B)
if len(p) > 0:
    t = min(p)
print(t)