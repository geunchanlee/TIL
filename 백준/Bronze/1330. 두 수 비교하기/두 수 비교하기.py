import sys
A, B = map(int, sys.stdin.readline().split())
if A > B:
    print('>')
if A < B:
    print('<')
if A == B:
    print('==')