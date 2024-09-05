N, K = map(int,input().split())

l = [i for i in range(1,N+1)]
josephus = []
i = 0
while len(l) > 0:
    p = i + K-1
    if p >= len(l):
        p = p % len(l)
    josephus.append(l.pop(p))
    i = p
print(f'<{", ".join(map(str, josephus))}>')