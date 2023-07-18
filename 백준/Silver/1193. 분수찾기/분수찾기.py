X = int(input())
idx = 1
while X > idx:
    X -= idx
    idx += 1
if idx % 2 ==0:
    print(f'{X}/{idx+1-X}')
else:
    print(f'{idx+1-X}/{X}')