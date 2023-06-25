w = input()
check = True
for i in range(len(w)):
    if w[i] == w[-(i + 1)]:
        pass
    else:
        check = False
if check:
    print(1)
else:
    print(0)