str = input()

for i in str:
    a = ord(i)
    if a < 97:
        a += 32
    else:
        a -= 32
    print(chr(a),end='')