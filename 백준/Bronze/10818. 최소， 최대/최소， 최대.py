import sys
N = input()
l = list(map(int, sys.stdin.readline().split()))
print(min(l), max(l))