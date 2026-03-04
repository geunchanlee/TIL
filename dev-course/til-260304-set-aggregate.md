# TIL 26/03/04 - SET연산자, 집계함수

## SET 연산자

독립적인 여러 쿼리를 하나로 묶는 역할

수학의 집합과 같은 개념

| 종류      | 설명                                                                     |
| --------- | ------------------------------------------------------------------------ |
| UNION     | 연결된 SELECT 결과 값을 합집합으로 묶어 줌. 결과 값의 중복 제거          |
| UNION ALL | 연결된 SELECT 결과 값을 합집합으로 묶어 줌. 중복 결과도 모두 출력        |
| INTERSECT | 먼저 작성한 SELECT와 다음 SELECT의 결과 값이 같은 데이터만 출력 (교집합) |
| EXCEPT    | 먼저 작성한 SELECT결과 값에서 다음 SELECT의 결과 값을 차집합 처리.       |

`INTERSECT`, `EXCEPT`연산자는 MySQL 8.0.31 이후부터 지원

---

## 집계함수

여러 행을 바탕으로 하나의 결과 값을 도출하기 위해 사용하는 함수

**SUM**
- 지정한 데이터의 합
- `SELECT SUM(column), SUM(DISTINCT column), SUM(ALL column) FROM table`

**COUNT**
- 지정한 데이터 개수
- `SELECT COUNT(*), COUNT (amount) FROM table`

**MAX, MIN**
- 최대값, 최소값
- `SELECT MAX(column), MIN(column) FROM table`

**AVG**
- 지정한 데이터 평균 값
- `SELECT AVG(column) FROM table`

**GROUP BY**
- 특정 범위를 지정해 `WHERE`구문 처리 후 그 결과에 대해 `GROUP BY` 적용
- 별칭 사용 가능 (MySQL)
- 정해준 기준으로 그룹을 만든다.
- `SELECT`구문에 그룹함수를 제외한 모든 컬럼, 표현식은 반드시 `GROUP BY`에 명시해야 함
- ```sql
  -- region 기준으로 그룹을 만들어 표시
  SELECT region, SUM(population) 
  FROM CITY
  GROUP BY region;
  ```

**WITH ROLLUP**
- 총합 또는 중간 합계가 필요한 경우 GROUP BY와 함께 사용
- GROUP BY와 같이 사용해야 한다. GROUP BY의 하위 메서드 같이 생각하고 사용하자.


**HAVING**
- SELECT문에 GROUP BY가 존재할 때 사용하는 옵션
- GROUP BY 결과로 나온 값의 범위를 제한하는 데 사용한다.
- 별칭 사용 가능 (MySQL)
- ```sql
  SELECT region, SUM(population) as Population
  FROM CITY
  GROUP BY region
  HAVING Population > 300
  ORDER BY Population DESC;
  ```


**GROUP_CONCAT**
- MySQL 전용
- 그룹화된 데이터의 문자열 값을 연결해준다

---

## 쿼리 실행 순서

> SELECT 문장의 실행 순서

위에서 아래로 실행된다.
⭐️ 기억하기!

1. `FROM`
2. `WHERE`
3. `GROUP BY`
4. `HAVING`
5. `SELECT`
6. `ORDER BY`
7. `LIMIT/OFFSET`
