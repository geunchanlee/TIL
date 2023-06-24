def roundFive(v, num):  # python 반올림 방식차이 해결용 함수
    return round(v + 10 ** (-len(str(v)) - 1), num)

C = int(input())
l = [list(map(int, input().split())) for _ in range(C)]
for i in range(C):
    up = 0
    N = l[i][0]
    score_sum = sum(l[i]) - N
    average = score_sum / N
    for j in l[i][1:]:
        if j > average:
            up += 1
    print(f"{roundFive(up / N * 100, 3):.3f}%")