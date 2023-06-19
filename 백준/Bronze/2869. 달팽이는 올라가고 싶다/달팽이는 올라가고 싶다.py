import sys
import math

A, B, V = map(int, sys.stdin.readline().split())
# (A-B) = up distance per day ,(V-B) = top of the stick
print(math.ceil((V - B) / (A - B)))
