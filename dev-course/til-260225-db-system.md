# TIL 26/02/25 - 데이터베이스 시스템 

## DataBase System

데이터베이스 정의

- 공유데이터
- 통합된 데이터
- 저장된 데이터
- 운영 데이터

---

### FILE System

OS 자체에서 데이터를 생상, 관리, 저장, 검색하는 시스템
폴더 & 파일로 구성되어 있다.

**단점**
- 데이터 중복 저장
	- 파일 단위 데이터 저장 때문에 동일 데이터의 중복 저장 발생가능
- 무결성 유지 어려움
	- 중복 데이터 변경 제어가 어렵다. 중복된 데이터간 불일치 가능
	- 데이터 변경을 모든 파일에서 수정해야 함
- 보안 취약
- 프로그램과 데이터간 독립성이 없음

### 데이터베이스 관리 시스템 발전과정

1. 세대: 네트워크•계층 DBMS
2. 세대: 관계 DBMS(RDBMS)
	- 데이터베이스를 테이블 형태로 구성하는 관계 데이터모델 이용
	- 오라클, MS-SQL, Access, MySql 등
3. 세대: 객체지향•객체관계 DBMS
	- 객체 개념을 이용해 데이터베이스를 구성하는 객체지향 데이터모델 이용 
	- O2, ONTOS, GemStone 등
4. 세대: NoSQL•NewSQL DBMS
	- MonggoDB, Cassandra, Redis 등

**RDBMS 종류**
- 오라클: RDBMS 대표
- IBM DB2
	- IBM시스템, 금융권에서 많이 사용
- MS-SQL
	- 마이크로소프트
- MySQL
- PostgreSQL
- MariaDB


### DBMS(데이터베이스 관리 시스템)

사용자(응용 프로그램)와 데이터베이스 사이에 위치해 데이터베이스를 공유할 수 있도록 관리해주는 소프트웨어

- 장점
	- 데이터 중복 최소화
	- 데이터 공유 가능
	- 데이터 일관성  유지
	- 데이터 무결성 유지
	- 데이터 보안 보장
- 단점
	- 파일 시스템보다 비싸다.
	- 구조 복잡성으로 인해 장애 발생 시 파악이 어려울 수 있다.


### 데이터베이스 시스템 구성요소

- **사용자**
	- User(End User): 응용 프로그램 사용자
	- application programmer: User가 사용할 수 있는 DBMS와 연동된 응용 프로그램 개발자
	- DBA(DataBase Administrator): DMBS및 이와 관련된 하드웨어&소프트웨어 관리자
- **데이터 언어**
	- 데이터 정의어(`DDL`, *Data Definition Language*)
		- 데이터베이스 스키마 정의, 수정
		- Create, Alter, Drop 등
	- 데이터 조작어(`DML`, *Data Manipulation Language*)
		- 데이터 CRUD하는 데 사용하는 언어
		- Insert, Update, Delete 등
	- 데이터 제어어(`DCL`, *Data Control Language*)
		- 데이터베이스 정확성 유지에 사용
		- Grant, Revoke 등
- **데이터베이스 관리시스템**
	- 데이터베이스 관리 소프트웨어
- **데이터베이스**
	- 데이터 구조화, 중복 최소화하여 통합 저장한 데이터 모임


## 데이터베이스 스키마

**Schema = 도식**
- 데이터베이스 내에서 데이터가 구성되는 방식 정의하는 논리적 구조.


### 데이터베이스 스키마 유형

1. 외부 스키마(External Schema) - 사용자 뷰
	- 개별 사용자 입장에서 데이터베이스 구조 기술한 것
	- 개별 사용자를 위한 여러 형태의 외부 스키마 존재
2. 개념 스키마(Conceptual Schema) - 전체적인 뷰
	- 조직 전체 입장에서 통합한 데이터베이스를 기술한 것
	- 하나의 개념 스키마만 존재
	- 데이터 간의 관계와 제약조건을 정의한 논리적 구조
	- 일반적으로 지칭되는 스키마
3. 내부 스키마(Internal Schema) - 저장장치 뷰
	- 저장장치 입장에서 전체 DB 저장되는 방법을 명세
	- 물리 저장장치에서 데이터가 사용하는 인덱스, 압축 방식, 저장 경로 등 구체적인 물리적 명세 포함

---

### 참고한 글

- ["데이터베이스 스키마란 무엇인가요?"](https://www.ibm.com/think/topics/database-schema), *IBM*
- iinaglow, ["스키마(Schema)의 개념 및 특징"](https://iingang.github.io/posts/DB-schema/), *iingang.github.io*