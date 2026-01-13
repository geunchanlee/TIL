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

줄바꿈 전까지의 한 줄을 배열에 저장

- 출력 

printf(), puts()

<br>

### 문자열 처리 라이브러리

> '#include <string.h>

1. strlen(s)

문자열 길이

2. strcpy(s1, s2)

문자열 복사

3. strcat(s1, s2)

문자열 붙여넣기

4. strcmp(s1, s2)

문자열 비교

<br>

### 문자열을 수치로 변환

~~~c
printf("%d\n", atoi("100")); //문자열을 정수 100으로

sscanf(s, "%d", &i); //문자열을 정수 100으로

sprintf(t, "%d", 100); // 숫자를 문자열로
~~~

atoi(), atof()

sscanf, sprinf 굉장히 많이 쓰인다

--- 

문자열 비교할 땐 ==를 사용해 비교하지 말자 

-> 반드시 strcmp()를 사용할 것

문자열 배열에 초기화 문장이 아니면 직접적으로 넣을 수 없다

-> strcpy()를 사용하자

---

### 문자열과 포인터

문자열과 포인터가 어떻게 다른지 알기 (변경가능, 불가능)

> char *p = "hello"
 
여기서 hello는 변할 수 없는 문장

> char s[] = "Hello world"

여기는 값을 변경할 수 있다

### 문자열의 배열

문자열의 이중 배열 = 배열이기 때문에 수정가능

래그드 배열 = 공간 낭비는 없어지지만 포인터 배열이기 때문에 수정이 불가

- EOF(End Of File) = CTRL + D

### strtok

> char * strtok(char *s, char *delimeter)

s 자리에 처음 호출할 때는 문자열을 넣고 그 이후에 호출할 땐 NULL을 넣는다
