def mergeSort(a, l, r):
    if r > l:
        m = int((l + r) / 2)
        mergeSort(a, l, m)
        mergeSort(a, m + 1, r)
        i, j, k = l, m + 1, l
        while i <= m and j <= r:
            if a[i] < a[j]:
                b[k] = a[i]
                k += 1
                i += 1
            else:
                b[k] = a[j]
                k += 1
                j += 1
        if i > m:
            for p in range(j, r + 1):
                b[k] = a[p]
                k += 1
        else:
            for p in range(i, m + 1):
                b[k] = a[p]
                k += 1
            for p in range(l, r + 1):
                a[p] = b[p]


def checkSort(a, n):
    Sorted = True
    for i in range(1, n):
        if a[i] > a[i + 1]:
            Sorted = False
        if Sorted == False:
            break
    if Sorted:
        print("정렬 완료\n")
    else:
        print("정렬 오류 발생\n")


import random, time

a = []
N = 100000
a.append(None)
for i in range(N):
    a.append(random.randint(1, N))
b = a.copy()
start_time = time.time()
mergeSort(a, 1, N)
end_time = time.time() - start_time
print("합병 정렬의 실행 시간 (N = %d) : %0.3f" % (N, end_time))
checkSort(a, N)
