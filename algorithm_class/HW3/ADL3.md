## (1) 퀵 정렬
~~~c
quickSort(a[], l, r)
    if (r > l) then {
        i <- partition(a, l, r)
        quickSort(a, l, i-1);
        quickSort(a, i+1, r);
    }
end quickSort()

partition(a[], l, r)
    v <- a[r]; // 가장 오른쪽 원소를 피봇으로 정함
    i <- l-1;  // 왼쪽에서 오른쪽으로 움직이는 포인터
    j <- r;    // 오른쪽에서 왼쪽으로 움직이는 포인터
    for (;;) do {
        do {i <- i + 1;} while (a[i] < v);
        do {j <- j - 1;} while (a[j] > v);
        if (i ≥ j) then break; 
        a[i]와 a[j]교환;
    }
    a[i]와 a[r] 교환;
    return i;
end partition()
~~~

**N = 100000** 일 때
- N  실행시간: 0.066
- 2N 실행시간: 0.141
- 3N 실행시간: 0.215

- N이 정렬됐을 때 실행시간: 55.885
- N이 역순 정렬됐을 때 실행시간: 88.343

<br>

## (2) 합병 정렬
~~~c
merge(a[], l, m, r)
    i <- l; j <- m+1; k <- l;
    // 배열 b는 함수 외부에서 "b = a.copy()" 명령문을 사용하여 주어진다고 가정
    // a[i]와 a[j]를 비교하여 작은 값을 b[k]에 저장
    while (i ≤ m and j ≤ r) do {
        if (a[i] < a[j]) then {
            b[k] <- a[i];
            k <- k + 1; i <- i + 1
        }
        else {
            b[k] <- a[j];
            k <- k + 1; j <- j + 1;
        }
    }
    if (i > m) then
        for (p <- j; p ≤ r; p <- p + 1) do {
            b[k] <- a[p];
            k <- k + 1;
        }
    else
        for (p < - i; p ≤ m; p <- p + 1) do {
            b[k] <- a[p];
            k <- k + 1;
        }
    for (p <- l; p ≤ r; p <- p + 1) do
        a[p] <- b[p];
end merge()
~~~

**N = 100000** 일 때
- N  실행시간: 0.182
- 2N 실행시간: 0.376
- 3N 실행시간: 0.594

- N이 정렬됐을 때 실행시간: 0.176
- N이 역순 정렬됐을 때 실행시간: 0.177

<br>

## (3) 히프 정렬
~~~c
heapify(a[], h, m)
    // 루트 h를 제외한 h의 왼쪽 서브트리와 오른쪽 서브트리는 히프
    // 현재 시점으로 노드의 최대 레벨 순서 번호는 m
    v <- a[h];
    for (j <- 2*h; j ≤ m; j <- 2*j) do {
        if (j < m and a[j] < a[j+1]) the j <- j + 1;
        if (v ≥ a[j]) the exit;
        else a[j/2] <- a[j];
    }
    a[j/2] <- v;
end heapify()
~~~

**N = 100000** 일 때
- N  실행시간: 0.169
- 2N 실행시간: 0.370
- 3N 실행시간: 0.593

- N이 정렬됐을 때 실행시간: 0.169
- N이 역순 정렬됐을 때 실행시간: 0.157