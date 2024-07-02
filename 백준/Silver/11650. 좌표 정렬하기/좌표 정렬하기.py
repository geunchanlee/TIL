import sys

input = sys.stdin.readline
N = int(input())
coordinates = {}

for i in range(N):
    x, y = map(int, input().split())
    if x not in coordinates:
        coordinates[x] = []
    coordinates[x].append(y)

ans = sorted(coordinates.items())
for x, y_list in ans:
    y_list.sort()
    for y in y_list:
        print(x, y)