H, M = map(int,input().split())
T = int(input())
cookt = M + T

if cookt >= 60: 
    H += cookt//60
    cookt = (cookt % 60)
if H >= 24:
    H -= 24
print(H,cookt)