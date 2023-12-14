def encipher(plain, n, p):
    cipher = ""
    i = 0
    while i < len(plain):
        m = ""
        for j in range(4):
            m += plain[i + j]
        i += 4
        a = int(m)
        t = a
        for k in range(p):
            b = t % n
            t = a * b
        if b < 10:
            cipher += "000" + str(b)
        elif b < 100:
            cipher += "00" + str(b)
        elif b < 1000:
            cipher += "0" + str(b)
        else:
            cipher += str(b)
    return cipher


def encode(plain):
    n = len(plain)
    m = ""
    for i in range(n):
        a = ord(plain[i])
        if a == 32:
            a = 64
        a -= 64
        if a == 0:
            m += "00"
        elif a < 10:
            m += "0" + str(a)
        else:
            m += str(a)
    return m


plainText = "SAVE PRIVATE RYAN "
N = 3713
S = 97
P = 37
plainMessage = encode(plainText)
print("평  문 : ", plainMessage)
cipherMessage = encipher(plainMessage, N, P)
print("암호문 : ", cipherMessage)
