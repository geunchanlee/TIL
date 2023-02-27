A, B, C = map(int, input().split())
if A > B:
    A, B = B, A
if B > C:
    B, C = C, B
if A > B:
    A, B = B, A
print(B)