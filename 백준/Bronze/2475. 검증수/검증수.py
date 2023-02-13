a = list(map(int,input().split()))
print(sum([i*i for i in a])%10)