S = input()
ans = set()
checker = 1
while checker < len(S)+1:
    for i in range(len(S)):
        ans.add(S[i:i+checker])
    checker += 1
print(len(ans))