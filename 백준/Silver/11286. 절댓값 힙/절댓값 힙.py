import sys, heapq

input = sys.stdin.readline
N = int(input())
heap = []
dap = []

for i in range(N):
    x = int(input())
    if x != 0:
        heapq.heappush(heap, (abs(x),x))
    else:
        if not heap:
            print(0)
        else:
            print(heapq.heappop(heap)[1])