import sys

A, B, C = map(int, sys.stdin.readline().split())
if A > B:
    A, B = B, A
if B > C:
    B, C = C, B
if A > B:
    A, B = B, A
print(B)