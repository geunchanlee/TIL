import heapq, sys

input = sys.stdin.readline
heap = []

N = int(input())
for i in range(N):
    X = int(input())
    if X != 0:
        heapq.heappush(heap, X)
    else:
        if len(heap) == 0:
            print(0)
        else:
            print(heapq.heappop(heap))