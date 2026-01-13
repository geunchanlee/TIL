def makeRun(a, n):
    r = []
    i = 1
    start = 1

    if n <= 1:
        return a
    while i < n:
        if a[i] < a[i - 1]:
            r.append(a[start:i])
            start = i
        i += 1
    r.append(a[start:i])
    return r

