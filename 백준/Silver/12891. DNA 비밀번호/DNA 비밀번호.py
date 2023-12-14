import sys

input = sys.stdin.readline
S, P = map(int, input().split())
dna = [_ for _ in input().rstrip()]
min_cnt = list(map(int, input().split()))

checker = ["A", "C", "G", "T"]
password = [0, 0, 0, 0]


def add_num(n):
    for i in range(4):
        if n == checker[i]:
            password[i] += 1


def check():
    for i in range(4):
        if password[i] < min_cnt[i]:
            return False
    return True


for i in dna[0:P]:
    add_num(i)
cnt = 0
if check() == True:
    cnt = 1

for i in range(P, S):
    add_num(dna[i])
    for j in range(4):
        if dna[i - P] == checker[j]:
            password[j] -= 1

    if check() == True:
        cnt += 1
print(cnt)
