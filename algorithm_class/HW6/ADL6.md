## (1) 레드 블랙 트리 탐색 알고리즘
~~~c
black <- 0;
red <- 1;

insert(T, v)
// p : x의 부모 노드, g : x의 조부모 노드, gg : x의 증조부모 노드
    x <- T; p <- T; g <- T;
    while (x ≠ null) do {
        gg <- g; g <- p; p <- x;
        if (x.key = v) then return;
        if (x.key > v) then x <- x.left;
        else x <- x.right;
        if ((x.left.color = red) and (x.right.color = red)) then
            split(x, p, g, gg, v);
    }
    x <- color가 red이고 key값이 v인 새로운 노드;
    if (p.key > v) then p.left <- x;
    else p.right <- x;
    split(x, p, g, gg, v);
end insert()

split(x, p, g, gg, v)
    x.color <- red;
    x.left.color <- black;
    x.right.color <- black;
    if (p.color = red) then {
        g.color <- red;
        if((g.key > v) ≠ (p.key > v)) then
            p <- rotate(v,g);
        x <- rotate(v, gg);
        x.color <- black;
    }
end split()

rotate(v, y)
    // c : y의 자녀 노드, gc : y의 손자녀 노드
    if (y.key > v) then c <- y.left;
    else c <- y.right;
    if (c.key > v) then {
        gc <- c.left;
        c.left <- gc.right;
        gc.right <- c;
    }
    else {
        gc <- c.right;
        c.right <- gc.left;
        gc.left <- c;
    }
    if (y.key > v) then y.left <- gc;
    else y.right <- gc;
    return gc
end rotate();
~~~

<br>

## (5) 선형 탐사법
~~~c
insert(a[], v)
  x ← hash(v);
  while (a[x] ≠ -1) do x ← (x + 1) mod M;
  a[x] ← v;
end insert()

search(a[], v) 
  x ← hash(v);
  while (a[x] ≠ -1) do {
    if (a[x] = v) then return a[x];
    else x ← (x + 1) mod M;
  }
  return -1;
end search()

hash(v)
  return v mod M;
end hash()
~~~

<br>

## (6) 이중 해싱
~~~c
insert(a[], v)
  x ← hash(v);
  u ← hash2(v);
  while (a[x] ≠ -1) do x ← (x + u) mod M;
  a[x] ← v;
end insert()

search(a[], v) 
  x ← hash(v);
  u ← hash2(v);
  while (a[x] ≠ -1) do {
    if (a[x] = v) then return a[x];
    else x ← (x + u) mod M;
  }
  return -1;
end search()

hash(v)
  return v mod M;
end hash()

hash2(v)
  return 64 - (v mod 64);
end hash()
~~~