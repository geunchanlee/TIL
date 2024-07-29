n = int(input())
l = [0, 1, 2]
if n >= 3:
    for i in range(3,n+1):
        x = (l[i-1]+l[i-2])%10007
        l.append(x)
print(l[n])