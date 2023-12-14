def initNext(p):
    M = len(p)
    next[0] = -1
    i = 0
    j = -1
    while i < M:
        if j != -1 and p[i] == p[j]:
            next[i] = next[j]
        else:
            next[i] = j
        while j >= 0 and p[i] != p[j]:
            j = next[j]
        i += 1
        j += 1


pattern = [
    "aaaaaaaaa",
    "00000001",
    "10100111",
    "ababca",
    "abababca",
    "abcabcabc",
    "abcabcabcab",
    "abracadabra",
]
for p in range(8):
    next = [0] * 50
    M = len(pattern[p])
    initNext(pattern[p])
    print(f"({p+1}) {pattern[p]}:", end=" ")
    for i in range(1, M):
        print(next[i], end=" ")
    print()
