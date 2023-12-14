def decipher(text, K):
    n = len(text)
    deciphered = ""
    for i in range(n):
        for j in range(27):
            if text[i] == K[j]:
                if j == 0:
                    deciphered += " "
                    break
                else:
                    deciphered += chr(j + 64)
                    break

    return deciphered


K = "QHCBEJKARWSTUVD IOPXZFGLMNY"
print(decipher("XHGJQIPWGHZJQPNHD", K))
