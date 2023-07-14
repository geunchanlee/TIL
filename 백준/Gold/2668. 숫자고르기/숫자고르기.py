import sys
N = int(sys.stdin.readline().rstrip())
t = {n:int(sys.stdin.readline().rstrip()) for n in range(1,N+1)}
ans = []
for k, v in t.items():
    if k == v:
        ans.append(k)
    else:
        c = t[v]
        i = 0
        while i < N:
            if c == k:
                ans.append(c)
                break
            else:
                i += 1
                c = t[c]
print(len(ans))
for i in sorted(ans):
    print(i)