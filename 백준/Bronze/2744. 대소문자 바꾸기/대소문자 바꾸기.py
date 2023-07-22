ans = ''
for i in input():
    ans += i.lower() if i.isupper() else i.upper()
print(ans)