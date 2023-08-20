g = []
for i in range(1,10000):
    n = i
    for j in str(i):
        n += int(j)
    g.append(n)
for _ in range(1,10000):
    if _ not in g:
        print(_)