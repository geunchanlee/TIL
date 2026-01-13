def exchangeSort(a, n):
    for i in range(n):
        for j in range(n - 1, i - 1, -1):
            if a[j] > a[j - 1]:
                a[j - 1], a[j] = a[j], a[j - 1]


def checkSort(a, n):
    isSorted = True
    for i in range(0, n - 1):
        if a[i] < a[i + 1]:
            isSorted = False
        if not isSorted:
            break
    if isSorted:
        print("정렬 완료")
    else:
        print("정렬 오류 발생")


import random, time

N = 5000
a = []
a.append(-1)
for i in range(N):
    a.append(random.randint(1, N))
start_time = time.time()
exchangeSort(a, N)
end_time = time.time() - start_time
print("교환 정렬의 실행 시간 (N = %d) : %0.3f" % (N, end_time))
checkSort(a, N)
