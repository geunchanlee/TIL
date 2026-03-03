# TIL 26/03/03 - 데이터베이스 SELECT

## SELECT

- 데이터베이스로부터 저장된 데이터를 검색하는 데 사용한다.
- 컬럼 이름에 ALIAS 사용
	- `AS`로 컬럼에 별칭을 부여
	- AS없이 컬럼에 별칭 부여
	- `" "`로 별칭 부여

### 산술연산

**규칙**
- `*`와 `/` 연산은 `+`, `-` 연산 이전에 실행
- 우선순위 같은 경우엔 왼쪽에서 오른쪽으로 진행
- 연산자 우선순위를 임의로 바꾸려면 `()`사용

> [!hint] `NULL`의 연산 규칙
- `NULL`은 알 수 없는 값을 의미한다.
- `NULL`은 연산, 할당, 비교가 불가능하다.
	- NULL값이 포함된 연산의 결과는 NULL
- NULL 처리 함수를 이용한다
	- `IFNULL`: NULL이면 대체 값 반환
	- `COALESCE`: 첫 번째 NULL이 아닌 값 반환
	- `IF`: 조건식이 참이면 첫 번째 값, 거짓이면 두 번째 값 반환
	- `NULLIF`: 두 값이 같으면 NULL, 다르면 첫 번째 값 반환

---

### 예시 데이터

아래의 예시 데이터로 데이터 조회를 학습해보자.

```sql
CREATE TABLE CITY(
	num INT AUTO_INCREMENT NOT NULL PRIMARY KEY,
	name VARCHAR(10),
    population INT,
    region VARCHAR(10)
);

INSERT INTO CITY VALUES(NULL, 'Seoul', 931, '수도권');
INSERT INTO CITY VALUES(NULL, 'Incheon', 303, '수도권');
INSERT INTO CITY VALUES(NULL, 'Daejeon', 144, '충청권');
INSERT INTO CITY VALUES(NULL, 'Busan', 334, '경상권');
INSERT INTO CITY VALUES(NULL, 'Gwangju', 140, '전라권');
INSERT INTO CITY VALUES(NULL, 'Daegu', 236, '경상권');
INSERT INTO CITY VALUES(NULL, 'Ulsan', 109, '경상권');

SELECT * FROM CITY;
```

> 예시 데이터 `CITY` 테이블 
> 
| num | name    | population | region |
| --- | ------- | ---------- | ------ |
| 1   | Seoul   | 931        | 수도권 |
| 2   | Incheon | 303        | 수도권 |
| 3   | Daejeon | 144        | 충청권 |
| 4   | Busan   | 334        | 경상권 |
| 5   | Gwangju | 140        | 전라권 |
| 6   | Daegu   | 236        | 경상권 |
| 7   | Ulsan   | 109        | 경상권 |



### DISTINCT

중복 제거 

- 중복이 사라진 고유한 값을 반환해준다.

```sql
SELECT DISTINCT 컬럼1, 컬럼2, ... FROM 테이블명

SELECT DISTINCT region FROM CITY;
```
> 실행 결과
> 
| region |
| ------ |
| 수도권 |
| 충청권 |
| 경상권 |
| 전라권 |

`region`에서 중복이 없어진 값만 볼 수 있다.


### ORDER BY

SELECT구문의 마지막에서 사용됨
- 결과 데이터를 정렬한다
- ```sql
  SELECT 컬럼명 FROM 테이블명 ORDER BY 컬럼명 [ASC|DESC]
  
  SELECT * FROM CITY ORDER BY population DESC;
  ```
> 실행 결과
> 
| num | name    | population | region |
| --- | ------- | ---------- | ------ |
| 1   | Seoul   | 931        | 수도권 |
| 4   | Busan   | 334        | 경상권 |
| 2   | Incheon | 303        | 수도권 |
| 6   | Daegu   | 236        | 경상권 |
| 3   | Daejeon | 144        | 경상권 |
| 5   | Gwangju | 140        | 전라권 |
| 7   | Ulsan   | 109        | 경상권 | 

- `population`기준 내림차순으로 정렬되었다.
- 정렬 방향: `ASC`(오름차순), `DESC`(내림차순)
	- 정하지 않으면 기본은 `ASC`

---

## WHERE 조건과 연산자

WHERE 조건을 만족하는 데이터만 검색
- 조건(condition)
	- 하나 이상의 column, 표현식, 상수 및 비교 연산자의 결합
	- 표현식과 논리연산자가 결하보디어 그 결과가 TRUE, FALSE, UNKNOWN값을 반환
	- ‼️ 문자, 날짜는 `' '(작은 따옴표)`안에 표시해야 한다
- ```sql
	  SELECT 컬럼명 FROM 테이블명 WHERE 조건;
	  
	  SELECT * FROM CITY WHERE population >= 300; -- 예시 1
	  SELECT * FROM CITY WHERE name = 'Incheon' OR name = 'Daejeon'; -- 예시 2
  ```


### 비교 연산자

- `=`, `>`, `<`, `>=`, `<=` 
- `<>`, `!=` = 같지 않다
- 조건(condition): COLUMN, 연산자, 비교대상 값의 결합

> *예시 1*  `population >= 300` 실행 결과
> 
| num | name    | population | region |
| --- | ------- | ---------- | ------ |
| 1   | Seoul   | 931        | 수도권 |
| 2   | Incheon | 303        | 수도권 |
| 4   | Busan   | 334        | 경상권 |
- 주어진 조건으로 결과를 얻었다.

### 논리 연산자

비교연산자 사이에 논리연산자를 넣을 수 있다.
- `AND`, `OR`, `NOT`

> *예시 2*  `name = 'Incheon' OR name = 'Daejeon` 실행 결과
> 
| num | name    | population | region |
| --- | ------- | ---------- | ------ |
| 2   | Incheon | 303        | 수도권 |
| 3   | Daejeon | 144        | 충청권 |
-  주어진 조건을 `OR`로 연결한 결과를 얻었다.

### BETWEEN ... AND ...

컬럼 값이 특정 범위에 속하는지 확인

- 조건 A **이상** B **이하**에 속하는 값을 반환한다.
- ```sql
  SELECT 컬럼명 FROM 테이블명 WHERE 컬럼명 BETWEEN 조건A AND 조건B;
  -- 아래와 위 구문은 같다
  SELECT 컬럼명 FROM 테이블명 WHERE 컬럼명 >= 조건 A AND 컬럼명 <= 조건 B;
  
  -- 두 구문은 같은 결과를 얻을 수 있다.
  SELECT * FROM CITY WHERE population BETWEEN 100 AND 200;
  SELECT * FROM CITY WHERE population >= 100 AND population <= 200;
  ```

> 실행 결과
> 
| num | name    | population | region |
| --- | ------- | ---------- | ------ |
| 3   | Daejeon | 144        | 충청권 |
| 5   | Gwangju | 140        | 전라권 |
| 7   | Ulsan   | 109        | 경상권 | 
- 조건으로 주어진 100 이상 200 이하에 속하는 값을 얻을 수 있다.


### LIKE, 와일드 카드

패턴을 검색한다.
- 컬럼에 저장된 데이터의 일부가 포함된 데이터 조회

와일드 카드: 특정 문자 또는 문자열을 대체하거나 문자열 데이터의 패턴을 표기하는 특수문자
- `_`: 어떤 값이든 상관없이 한 개의 문자 데이터를 의미
- `%`: 길이와 상관없이 모든 문자 데이터를 의미
- ```sql
  SELECT 컬럼명 FROM 테이블명 WHERE 조건 LIKE ''
  
  -- name 컬럼이 'D'로 시작하는 데이터를 찾는다
  SELECT * FROM CITY WHERE name LIKE 'D%';
  -- D로 시작하는 Daejeon, Daegu행이 표시된다
  
  -- 두 번째 글자가 'n'인 데이터 검색
  SELECT * FROM CITY WHERE name LIKE '_n%';
  -- 두 번째 글자가 n인 Incheon 행이 표시된다
  
  -- 아무 곳에나 'eo'가 포함된 데이터 검색
  SELECT * FROM CITY WHERE name LIKE '%eo%';
  -- 단어에 eo가 들어있는 Seoul, Incheon, Daejeon행이 표시된다
  
  -- 아무 곳에나 'a'가 포함되지 않은 데이터 검색
  SELECT * FROM CITY WHERE name NOT LIKE '%a%';
  -- 단어에 a가 들어있지 않은 Seoul, Incheon행이 표시된다
  ```

### IS NULL
- NULL은 무슨 값인지 확정되지 않은 상태이거나 값 자체가 존재하지 않는 상태이다.
- 임의의 컬럼이 NULL인지 아닌지를 구별하기 위해 IS NULL을 사용
- ‼️ NULL 비교는 `=`연산자가 아닌 `IS NULL`, `IS NOT NULL`을 사용한다.
```sql
SELECT 컬럼명 FROM 테이블명 WHERE 컬럼명 IS NULL; -- 컬럼명 = NULL 처럼 쓰면 안 된다!!
SELECT 컬럼명 FROM 테이블명 WHERE 컬럼명 IS NOT NULL;
```


### LIMIT (MySQL)

특정 개수의 데이터를 출력할 때 사용한다

```sql
SELECT 컬럼명 FROM 테이블명 WHERE 조건 LIMIT num;

-- 2개만 출력
SELECT * FROM CITY LIMIT 2;

-- 2번째부터(3번째 행부터) 3개 출력
SELECT * FROM CITY LIMIT 2, 3;
-- OFFSET을 사용한 표현 방식 (위와 같다)
SELECT * FROM CITY LIMIT 3 OFFSET 2;
```
> `LIMIT 2` 실행 결과
> 
| num | name    | population | region |
| --- | ------- | ---------- | ------ |
| 1   | Seoul   | 931        | 수도권 |
| 2   | Incheon | 303        | 수도권 | 

> `LIMIT 2, 3`과 `LIMIT 3 OFFSET 2` 실행결과
> 
| num | name    | population | region |
| --- | ------- | ---------- | ------ |
| 3   | Daejeon | 144        | 충청권 |
| 4   | Busan   | 334        | 경상권 |
| 5   | Gwangju | 140        | 전라권 | 

- `LIMIT 2, 3`은 3번째 행부터 3개를 출력한다.
	- 인덱스가 0부터 시작하기 때문에 3번째 행이 `2`!
- `LIMIT 3 OFFSET 2`은 3개를 출력하는데 2번 부터 3개를 출력하기 때문에 결과가 위와 같다.

---

["SQL WHERE Clause"](https://www.w3schools.com/sql/sql_where.asp), *W3Schools*
