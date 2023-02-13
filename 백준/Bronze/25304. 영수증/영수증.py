X = int(input())
N = int(input())
o = 0
for i in range(N):
    a, b = input().split()
    o += (int(a) * int(b))
if o == X:
    print("Yes")
else:
    print("No")
