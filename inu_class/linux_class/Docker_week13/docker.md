# week12 Docker

### 하이퍼바이저 도커 차이

소스코드를 주고받는 경우 → 컴파일 시키고 실행해야 하는데 환경이 달라 에러가 발생할 확률 높음

docker이미지를 주고받으면 환경 자체를 전달하기 때문에 이런 걱정 x

docker engine =  vmware

도커파일 만들기 (yml)

Dockerhub = docker 이미지를 관리하는 클라우드 저장소

이미지를 내려받아서 컴퓨터에서 실행하면 = 도커 컨테이너 생성 이라고 함

하나의 이미지로 컨테이너 여러개를 만들 수 있다.

기존 가상화 기술은 OS를 독립적으로 설치 

도커는 따로 설치 없이 사용자 OS를 끌어 씀

컨테이너는 실행에 필요한 라이브러리, 실행파일만 존재해서 이미지 크기가 작고 host os에 부담이 적다

컨테이너에 필요한 모든 커널 자원은 host 커널 자원을 공유해서 사용함

---

### 도커 컨테이너 장점

- 마이크로서비스(MICROSERVICES) 개발 가능

    - 모놀리스(Monolith) 어플리케이션에 비해 모듈을 독립적 형태로 구성해 관리가 용이하다

    - 마이크로 서비스 개발은 컴포넌트간의 느슨한 결합으로 개발할 수 있게 하는데, 
    이는 서비스를 구성하는 한 부분에서 에러 발생시 다른 컨테이너는 놔두고 그 컨테이너만 다시 생성 가능 → 유지보수가 매우 깔끔하다

<br>

## Docker 명령어

### Docker Image & Container

- 도커 이미지

    - 컨테이너 생성시 필요한 요소
    - 이름 구성
        - [저장소 이름]/[이미지 이름]:[태그]
    - 저장소 이름 생략 가능
    - 도커 허브에서 이미지를 내려받음


- 도커 컨테이너

    - 하나의 완전히 격리된 프로세스 → 이 안에서 일어나는 일이 다른 곳(호스트, 다른 컨테이너)에 영향을 주지 않음

### Docker container 생성

- 도커 엔진 버전 확인
    - $ docker -v

- 도커 컨테이너 생성 및 실행
    - $ docker run -i -t ubuntu:22.04
        - -i 옵션: 컨테이너와 상호 입출력
        - -t 옵션: bash쉘 사용

- 컨테이너 내부 → 호스트
    - exit or Ctrl + D : 컨테이너 동작 중지
    - Ctrl + P, Q : 컨테이너를 중지하지 않고 나감

- 이미지 내려받기
    - $ docker pull centos:7

- 호스트에 있는 도커 이미지 확인
    - $ docker images

- 이미지로부터 컨테이너 생성
    - $ docker create -i -t —name mycentos centos:7
        - —name 옵션: 컨테이너 이름 설정
        - 컨테이너만 생성하고 들어가진 않는다

- 생성된 컨테이너 내부로 접속하기
    - $ docker start mycentos(컨테이너 이름)
    - $ docker attach mycentos
    - 이름 대신 Container ID로 접속 가능

### Docker container 목록 확인

- 컨테이너 목록 확인
    - $ docker ps
    - $ docker ps -a
        - -a 옵션: 정지된 컨테이너를 포함해 출력
- 컨테이너 이름 변경
    - $ docker rename [기존이름] [새이름]

### Docker container 삭제

- 컨테이너 삭제
    - $ docker rm [컨테이너이름]
    - 실행 중 컨테이너 삭제 시 에러 발생

- 컨테이너 정지 후 삭제
    - $ docker stop [컨테이너이름]
    - $ docker rm [컨테이너이름]
    - $ docker -f [컨테이너이름]
        - 실행중인 컨테이너 강제로 삭제

- 컨테이너 일괄 삭제
    - $ docker container prune

--- 

Q. 이미지에서 컨테이너를 만들고 거기서 작업한 내용을 남겨두고 싶다면??

A. 만들어진 컨테이너를 가지고 이미지를 만들어내야 한다

<br>

## 도커 컨테이너 기반 어플리케이션 구축

실제 배포에서는 웹서버, DB를 도커 컨테이너 여러개로 분리해서 만듬

두 컨테이너가 각각의 포트끼리 연결되어 웹서버에서 db에 쿼리를 하면 데이터를 찾아서 서버에 전달함

→ 컨테이너간 통신으로 마이크로서비스 운용

Q. 이렇게 구성하는게 어렵지 않나요?

A. 도커파일로 이런 컨테이너들을 만들겠다고 써두면 명령 하나만으로 전부  설정된 상태로 만들기 가능

- mysql 이미지 기반으로 데이터베이스 컨테이너 생성

    - $ docker run -d --name wordpressdb -e MYSQL_ROOT_PASSWORD=1234 -e MYSQL_DATABASE=wordpress arm64v8/mysql:latest
    
- wordpress이미지 기반으로 웹서버 컨테이너 생성
    
    - $ docker run -d --name wordpress -e WORDPRESS_DB_PASSWORD=1234 --link wordpressdb:mysql -p 80 wordpress`
    


## 도커 볼륨

DB를 어디에 저장해야 하는가? → 컨테이너 내부에 저장하면 컨테이너 삭제시 같이 지워지기 때문에 반드시 **호스트 머신**에 하드디스크 안에 데이터가 보관되어야 한다.

이렇게 해야 데이터베이스를 삭제시켰을때 호스트 디렉토리에 파일은 남아있기 때문에 다시 똑같은 이미지를 통해서 컨테이너를 다시 만들면 호스트에 보관되어 있던 파일을 마운트시켜서 서비스를 지속 가능하다

<br>

## 도커 이미지

### 도커 이미지 생성하기

도커 컨테이너에서 작업한 내용을 보존하기 위해 그 상태로 이미지를 만들 수 있다.

- 우분투 컨테이너 하나 생성하고 작업 수행

    - $ docker run -it —name incheon ubuntu:22.04
    - root: /# echo Incheon National University >> first.txt
    
- ctrl + P,Q로 빠져나와서 확인하고 이미지 생성

    - $ docker ps (컨테이너 계속 실행중인 모습 확인)
    - $ docker commit -a “chan” -m “my first docker image” **incheon** **incheon:0.1**

        - -a 옵션: 저자, -m 옵션: 커밋 메세지
        - **incheon** = 컨테이너 이름
        - **incheon:0.1** = 이미지 이름과 태그
        
- 기존 컨테이너 삭제하고 이미지에서 새로 컨테이너 만들어 확인해보기

    - $ docker stop incheon, docker rm incheon
    - $ docker run -it —name songdo incheon:0.1
    - 확인해보면 incheon 컨테이너에서 만든 first.txt 파일이 있음
    

### Docker Hub

- docker hub에서 레포지토리 생성하기

- 태그 작업후 repository에 push

    - $ docker login
    - $ docker tag incheon:0.1 geunchanlee/incheon:0.1
    - $ docker push geunchanlee/incheon:0.1

- 이미지 삭제

    - docker rmi incheon:0.1

- docker inspect incheon:0.2

    - 이미지 검사 기능
    - 레이어 보기
