## (1) 칵테일 쉐이커 정렬
~~~c
cocktailShakerSort(a[], n)
    d <- true; i <- 1; k <- n;
    while (i ≤ k) do {
        if (d = true) then {
            for (j <- i; j < k; j <- j + 1) do
                if (a[j] > a[j+1]) then a[j]와 a[j+1]을 교환;
            d <- false;
            k <- k - 1;
        }
        else {
            for (j <- k; j > i; j <- j - 1) do
                if (a[j] < a[j - 1]) then a[j]와 a[j-1]을 교환;
            d <- true;
            i <- i + 1;
        }
    }
end cocktailShakerSort()
~~~
**N = 5000** 일 때
- N  실행시간: 0.569
- 2N 실행시간: 2.253
- 3N 실행시간: 5.380

- N이 정렬됐을 때 실행시간: 0.339
- N이 역순 정렬됐을 때 실행시간: 0.728

<br>

## (2) 교환 정렬
~~~c
exchangeSort(a[], n)
    for (i <- 0; i < n; i = i + 1) do{
        for (j <- n-1, j > i-1, j <- j - 1) do {
            if (a[j] > a[j-1]) then a[j]와 a[j-1]을 교환;
        }
    }

end exchangeSort()
~~~
**N = 5000** 일 때
- N  실행시간: 0.581
- 2N 실행시간: 2.331
- 3N 실행시간: 5.185

- N이 정렬됐을 때 실행시간: 0.714
- N이 역순 정렬됐을 때 실행시간: 0.328

<br>

## (3) 자연 합병 정렬
~~~c
makeRun(a[], n)
    i <- 1;
    r <- [];  // 공백 리스트
    start <- 1;

    if (n ≤ 1) then return a;

    while (i < n) do {
        if (a[i] < a[i-1]) then {
            a[start:i]를 r에 넣기;
            start <- i;
        }
        i <- i + 1;
    }
    a[start:i]를 r에 넣기;
    return r;
    
end makeRun()
~~~  
