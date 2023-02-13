import sys
a = [int(sys.stdin.readline()) for i in range(9)]
r = max(a)
print(r, a.index(r)+1, sep='\n')