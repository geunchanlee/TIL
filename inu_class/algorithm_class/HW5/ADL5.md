## (1) 순차 탐색 알고리즘
~~~c
sequentialSearch(a[], search_key, n)
    i <- 0;
    while (i < n and a[i].key ≠ search_key) do
        i <- i + 1;
    if (i = n) then return -1;
    else return i;
end sequentialSearch()
~~~
**N = 5000** 일 때
- N  실행시간: 0.400
- 2N 실행시간: 1.612
- 3N 실행시간: 3.605

<br>

## (2) 이진 탐색 알고리즘
~~~c
binarySearch(a[], search_key, n) 
  left <- 0; right <- n - 1;
  while (left ≤ right) do {
    mid <- (left + right) / 2;
    if (a[mid].key == search_key) then return mid;
    if (a[mid].key > search_key) then right <- mid – 1;
    else left <- mid + 1;
  }
  return -1;
end binarySearch()
~~~
**N = 10000** 일 때
- N  실행시간: 0.016
- 2N 실행시간: 0.034
- 3N 실행시간: 0.051

<br>

## (3) 이진 트리 탐색 알고리즘
~~~c
binaryTreeSearch(T, search_key) 
  x <- T;
  while (x ≠ null) do {
    if (x.key = search_key) then return x.key;
    if (x.key > search_key) then x <- x.left;
    else x <- x.right;
  }
  return -1;
end binaryTreeSearch()
~~~
