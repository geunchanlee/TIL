A, B, C = map(int, input().split())
e = C-B
if 0 >= e:
    print(-1)
else:
    print(A//e+1)