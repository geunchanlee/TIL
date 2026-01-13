def decipher(text, K):
    n = len(text)
    deciphered = ""
    for i in range(n):
        a = ord(text[i])
        t = a - K
        if t < 65:
            t += 27
        if t == 91:
            t = 32
        deciphered += chr(t)
    return deciphered


print(decipher("TBWFAQSJWBUFASZBO", 1))
