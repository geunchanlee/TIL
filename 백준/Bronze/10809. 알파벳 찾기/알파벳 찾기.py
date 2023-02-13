a = 'abcdefghijklmnopqrstuvwxyz'
S = input()
for i in range(len(a)):
    if a[i] not in S:
        print(-1, end=' ')
    elif a[i] in S:
        print(S.index(a[i]), end=' ')