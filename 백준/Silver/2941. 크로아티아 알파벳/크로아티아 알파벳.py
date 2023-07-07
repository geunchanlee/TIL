alphabet = ['c=','c-','dz=','d-','lj','nj','s=','z=']
w = input()
cnt = 0
checker = ''
i = 0

while True:
    checker += w[i]
    if i < len(w)-1 and checker + w[i+1] in alphabet:
        cnt += 1
        checker = ''
        i += 2
    elif i < len(w)-2 and checker + w[i+1] + w[i+2] in alphabet:
        cnt += 1
        checker = ''
        i += 3
    else:
        cnt += 1
        checker = ''
        i += 1
    if i >= len(w):
        break
print(cnt)