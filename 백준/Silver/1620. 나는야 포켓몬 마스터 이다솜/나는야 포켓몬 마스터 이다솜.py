from sys import stdin
N, M = map(int,stdin.readline().split())
pokeDict = {v:input() for v in range(1,N+1)}
pokeDict_reverse = {v:k for k, v in pokeDict.items()}
for i in range(M):
    q = stdin.readline().rstrip()
    if q.isnumeric():
        print(pokeDict[int(q)])
    else:
        print(pokeDict_reverse[q])