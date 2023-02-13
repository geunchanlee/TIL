import sys
Word = sys.stdin.readline().upper().strip()
alpha = list(set(Word))
num = []
for i in alpha:
    num.append(Word.count(i))

if num.count(max(num)) >= 2:
    print('?')
else:
    print(alpha[num.index(max(num))])
