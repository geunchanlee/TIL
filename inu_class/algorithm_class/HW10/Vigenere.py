def decipher(text, K):
    deciphered = ""
    n = len(K)
    for i in range(len(text)):
        a = ord(text[i])
        if a == 32:
            a = 91
        b = ord(K[i % n]) - 64
        t = a - b
        if t < 64:
            t += 27
        if t == 64:
            t = 32
        deciphered += chr(t)
    return deciphered


print(decipher("TCYFBSSKYBVHATABP", "ABC"))
