## (1) 선택 정렬
~~~c
selectionSort(a[], n)
	for (i <- 1; i ≤ n; i <- i + 1) do {
		minIndex <- i;
		for (j <- i; j ≤ n;j <- j + 1) do
			if (a[j] < a[minIndex]) then minIndex <- j;
		a[i]와 a[minIndex]를 교환;
	}
end selectionSort()
~~~

**N = 5000** 일 때

- N  실행시간: 0.239

- 2N 실행시간: 0.931

- 3N 실행시간: 2.085


- N이 정렬됐을 때 실행시간: 0.230

- N이 역순 정렬됐을 때 실행시간: 0.235

<br>

## (2) 버블 정렬
~~~c
bubbleSort(a[], n)
    for (i <- n; i > 0; i <- i - 1) do 
        for (j <- 1; j ≤ i; j <- j + 1) do
            if (a[j] > a[j+1]) then a[j] 와 a[j+1]를 교환;
end bubbleSort()
~~~

**N = 5000** 일 때

- N  실행시간: 0.581

- 2N 실행시간: 2.343

- 3N 실행시간: 5.224

- N이 정렬됐을 때 실행시간: 0.318

- N이 역순 정렬됐을 때 실행시간: 0.705

<br>

## (3) 삽입 정렬

~~~c
insertionSort(a[], n)
    for (i <- 2; i ≤ n; i <- i + 1) do {
        k <- a[i]
        j <- i
        while (a[j-1] > k) do {
            a[j] <- a[j-1];
            j <- j - 1;
        }
        a[j] <- k;
    }
end insertionSort()
~~~

**N = 5000** 일 때
- N  실행시간: 0.265
- 2N 실행시간: 1.053
- 3N 실행시간: 2.379

- N이 정렬됐을 때 실행시간: 0.000
- N이 역순 정렬됐을 때 실행시간: 0.495

<br>

## (4) 쉘 정렬
~~~c
shellSort(a[], n)
    for (h <- 1; h < n; h <- 3Xh+1) do {}; // 첫번째 h 값 계산
    for (; h > 0; h <- h/3) do {
        for (i <- h + 1; i ≤ n; i <- i + 1) do {
            v <- a[i];
            j < - i;
            while (j > h and a[j-h] > v) do {
                a[j] <- a[j-h];
                j <- j - h
            }
            a[j] <- v;
        }
    }
end shellSort()
~~~

**N = 5000** 일 때
- N  실행시간: 0.005
- 2N 실행시간: 0.015
- 3N 실행시간: 0.026

- N이 정렬됐을 때 실행시간: 0.002
- N이 역순 정렬됐을 때 실행시간: 0.003

