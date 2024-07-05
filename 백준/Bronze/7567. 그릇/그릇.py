b = input()
h = 10
for i in range(1,len(b)):
    if b[i] != b[i-1]:
        h += 10
    else:
        h += 5
print(h)