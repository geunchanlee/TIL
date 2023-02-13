import sys
n = [int(sys.stdin.readline()) % 42 for i in range(10)]
r = []
for i in n:
    if i not in r:
        r.append(i)
        
print(len(r))
