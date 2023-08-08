from collections import deque
q = deque([int(_) for _ in range(1,int(input())+1)])
while len(q) != 1:
    q.popleft()
    q.append(q.popleft())
print(*q)