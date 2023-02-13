N = input()
count = 0
r = 0
if int(N) < 10:
    N_fix = '0' + N
else:
    N_fix = N

while True:
    r = str(int(N_fix[0])+int(N_fix[1]))
    N_fix = (N_fix[-1]+r[-1])
    count += 1
    if int(N_fix) == int(N):
        break
print(count)