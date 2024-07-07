def push(stack, x):
    stack.append(x)

def pop(stack):
    if len(stack) == 0:
        return -1
    else:
        return stack.pop()

def size(stack):
    return len(stack)

def empty(stack):
    if len(stack) == 0:
        return 1
    else:
        return 0

def top(stack):
    if empty(stack):
        return -1
    else:
        return stack[-1]


import sys

N = int(sys.stdin.readline())
stack = []
for _ in range(N):
    command = sys.stdin.readline().split()
    if len(command) == 2:
        push(stack, int(command[1]))
    else:
        if command[0] == 'pop':
            print(pop(stack))
        elif command[0] == 'size':
            print(size(stack))
        elif command[0] == 'empty':
            print(empty(stack))
        elif command[0] == 'top':
            print(top(stack))
