n = int(input())
l = [0, 1, 3]
if n >= 3:
    for i in range(3, n+1):
        l.append((l[i-1]+(l[i-2]*2))%10007)
print(l[n])