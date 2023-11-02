def binarySearch(a, key, left, right):
    if left <= right:
        mid = (left + right) // 2
        if key == a[mid]:
            return mid
        elif key < a[mid]:
            return binarySearch(a, key, left, mid - 1)
        else:
            return binarySearch(a, key, mid + 1, right)
    else:
        return -1


if __name__ == "__main__":
    a = [int(i) for i in input().split()]
    key = int(input("key : "))
    a = sorted(a)
    print("index :", binarySearch(a, key, 0, len(a)))
