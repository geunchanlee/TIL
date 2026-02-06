import sys

maxNum = -1
maxIndex = [0, 0]
for i in range(9):
    numbers = [int(i) for i in sys.stdin.readline().split()]
    if max(numbers) > maxNum:
        maxNum = max(numbers)
        maxIndex[0] = i + 1
        maxIndex[1] = numbers.index(maxNum) + 1

print(maxNum)
print(*maxIndex)
