a, b = [], []
for i in range(3):
    N, M = map(int,input().split())
    a.append(N)
    b.append(M)
for j in range(3):
    if a.count(a[j]) == 1:
        x = a[j]
    if b.count(b[j]) == 1:
        y = b[j]
print(x,y)