T = int(input())

for t in range(T):
    tc_num = int(input())
    arr = [int(i) for i in input().split()]
    scores = dict()

    for i in arr:
        if i in scores:
            scores[i] += 1
        else:
            scores[i] = 1

    mode_key = 0
    mode_value = 0
    for k, v in scores.items():
        if v > mode_value:
            mode_value = v
            mode_key = k
        elif v == mode_value and k > mode_key:
            mode_value = v
            mode_key = k

    print(f'#{tc_num} {mode_key}')