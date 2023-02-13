h = input()
hex_list = list('0123456789ABCDEF')
r = 0

for i in range(len(h)):
    s = hex_list.index(h[i])
    r += s * (16**(len(h)-(i+1)))
print(r)