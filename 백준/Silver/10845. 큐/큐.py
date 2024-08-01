import sys
from collections import deque

input = sys.stdin.readline
N = int(input())
q = deque()
for i in range(N):
    command = input().split()
    if len(command) == 2:
        q.append(int(command[1]))
    else:
        command = command[0]
        if command == 'pop':
            if not len(q):
                print(-1)
            else:
                print(q.popleft())
        elif command == 'size':
            print(len(q))
        elif command == 'empty':
            if q: print(0)
            else: print(1)
        elif command == 'front':
            if q:
                print(q[0])
            else:
                print(-1)
        elif command == 'back':
            if q:
                print(q[-1])
            else:
                print(-1)