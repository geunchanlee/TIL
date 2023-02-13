A = int(input())
B = int(input())
C = int(input())
r = str(A*B*C)
for i in range(10):
    print(r.count(str(i)))