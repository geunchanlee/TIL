from sys import stdin

N = int(input())
D = []
for i in range(N):
    operation = stdin.readline().rstrip()
    if "push_front" in operation:
        D.insert(0, int(operation[operation.index(" ") + 1 :]))
    elif "push_back" in operation:
        D.append(int(operation[operation.index(" ") + 1 :]))
    elif "pop_front" in operation:
        if not D:
            print(-1)
        else:
            print(D.pop(0))
    elif "pop_back" in operation:
        if not D:
            print(-1)
        else:
            print(D.pop())
    elif "size" in operation:
        print(len(D))
    elif "empty" in operation:
        if not D:
            print(1)
        else:
            print(0)
    elif "front" in operation:
        if not D:
            print(-1)
        else:
            print(D[0])
    elif "back" in operation:
        if not D:
            print(-1)
        else:
            print(D[-1])
