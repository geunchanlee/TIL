a, b, c = sorted(map(int,input().split()))
if a == b == c:
    Money = 10000+(a*1000)
elif a == b or b == c:
    Money = 1000+(b*100)
elif a == c:
    Money = 1000+(a*100)
else:
    Money = c*100
print(Money)