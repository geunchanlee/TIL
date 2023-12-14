fin = open("email.html", encoding="utf8")
text = fin.read()
fin.close()


def bruteForce(p, t, k):
    M = len(p)
    N = len(t)
    i = k
    j = 0
    while j < M and i < N:
        if t[i] != p[j]:
            i -= j
            j = -1
        i += 1
        j += 1
    if j == M:
        return i - M
    else:
        return i


pattern = "mailto"
pattern_end = '"'
k = 0
i = 0

while True:
    ptr_start = bruteForce(pattern, text, k)
    ptr_end = bruteForce(pattern_end, text, ptr_start + 7)
    k = ptr_end + 1
    i = k
    if k < len(text):
        print(text[ptr_start + 7 : ptr_end])
    else:
        break
