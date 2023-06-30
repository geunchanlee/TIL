import sys

group = 0
for N in range(int(input())):
    word = sys.stdin.readline().rstrip()
    for i in set(word):
        isGroup = True
        if word.count(i) >= 2:
            n = word.count(i)
            x = word.index(i)
            for j in range(1, n):
                if word[x] != word[x + j]:
                    isGroup = False
        if isGroup == False:
            break
    else:
        group += 1
print(group)