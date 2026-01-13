import makeRun
import random, time


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


my_list = []
N = 5000
my_list.append(-1)
for i in range(N):
    my_list.append(random.randint(1, N))
b = my_list.copy()


def merge_runs(left, right):  # function for merging the runs
    merged = []
    i = 0
    j = 0
    while i < len(left) and j < len(right):
        if left[i] < right[j]:
            merged.append(left[i])
            i += 1
        else:
            merged.append(right[j])
            j += 1
    merged.extend(left[i:])  # appending rest of 'left' to the 'merged' list
    merged.extend(right[j:])  # appending rest of 'right' to the 'merged' list
    return merged


def natural_merge_sort(my_list):
    if len(my_list) <= 1:  # checking if the my_list is already sorted
        return my_list
    runs = []
    start = 0
    end = 1
    while end < len(my_list):  # finding the runs in the my_list
        if my_list[end] < my_list[end - 1]:
            runs.append(my_list[start:end])
            start = end
        end += 1
    runs.append(my_list[start:end])
    while len(runs) > 1:  # merging the runs
        merged_runs = []
        i = 0
        while i < len(runs) - 1:
            merged_runs.append(merge_runs(runs[i], runs[i + 1]))
            i += 2
        if len(runs) % 2 == 1:
            merged_runs.append(runs[-1])
        runs = merged_runs
    return runs[0]


start_time = time.time()
merge_runs(1, N)
end_time = time.time() - start_time
print("합병 정렬의 실행 시간 (N = %d) : %0.3f" % (N, end_time))
checkSort(my_list, N)
