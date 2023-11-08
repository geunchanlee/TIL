### 11.2 수업

# 문자열

문자열에 한정적으로 **""**로 초기화할 수 있다. -> 자동적으로 마지막에 NULL('\0') 문자가 붙음

### NULL 문자 

**'\0'** = 0 = false

컴퓨터가 메모리상에서 문자열의 끝이 어디인지 알기 위해 필요하다.

### 문자열 배열의 초기화

1. 배열 초기화 방식

> char str[6] = {'H','e','l','l','o','\n'};

2. "" 초기화 방식

> char str[6] = "Hello";

3. 배열 크기 생략

> char str[] = "Hello";


출력시 형식지정자 __%s__ 사용

일반적으로 문자열 입력받을 땐 get_s()사용 

### 문자 입출력

- getchar(), getch()차이점

1. char x = getchar()

getchar()를 쓸 경우엔 키보드로부터 입력을 기다리기 때문에 입력을 기다릴 메모리 공간인 버퍼를 사용한다

문자를 누르면 버퍼에 들어가고 -> 엔터를 누르면 문자가 x로 할당됨

2. char x = getch()

getch()는 키보드로 문자를 누르면 버퍼로 들어가지 않고 곧바로 x로 들어감

getch, putch 윈도우에서는 앞에 _ 붙여서 사용

<br>

getchar, putchar = include <stdio.h>

getch, putch = include <conio.h>


### 문자열 입출력 함수

1. scanf("%s",s)

단어의 경우라고 생각하기(공백 없는 경우)

2. gets_s(char s[], int length)

줄바꿈 전까지의 한 줄을 배열에 저장