def cocktailShakerSort(a, n):
    d = True
    i = 1
    k = n
    while i <= k:
        if d == True:
            for j in range(i, k):
                if a[j] > a[j + 1]:
                    a[j], a[j + 1] = a[j + 1], a[j]
            d = False
            k -= 1
        else:
            for j in range(k, i, -1):
                if a[j] < a[j - 1]:
                    a[j - 1], a[j] = a[j], a[j - 1]
            d = True
            i += 1


def checkSort(a, n):
    isSorted = True
    for i in range(1, n):
        if a[i] > a[i + 1]:
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
a.append(None)
for i in range(N):
    a.append(random.randint(1, N))
start_time = time.time()
cocktailShakerSort(a, N)
end_time = time.time() - start_time
print("칵테일 쉐이커 정렬의 실행 시간 (N = %d) : %0.3f" % (N, end_time))
checkSort(a, N)
