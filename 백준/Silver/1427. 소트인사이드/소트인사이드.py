N = input()
s = []
for i in N:
    s.append(i)
print("".join(sorted(s, reverse=True)))