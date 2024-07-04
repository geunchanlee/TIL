
### fopen, fclose

fopen()은 FILE 구조체를 가리키는 포인터를 반환

### 파일 모드

r: read

> 읽기 모드로 파일 오픈

w: write 

> 쓰기 모드로 파일 생성, 존재하면 내용 지워짐

a: append

> 추가 모드로 파일 생성, 존재하면 파일 끝에 데이터 추가


fopen뒤에는 fp가 NULL인지 아닌지 반드시 체크해야 한다

### 문자 단위 입출력

fputc(c, fp)

프로그램들이 실행될때의 인스턴스 = 프로세스

exit(1) -> 프로세스 종료

관례상으로 0은 성공을 나타내고 1은 오류

fgetc(fp)

c = fgetc(fp)

문자를 하나 받아서 c에 넣는다

c가 char가 아닌 정수형이어야 한다.

<br>

fputc,fgetc 를 fputs,fgets로 쓰면 한 문자가 아닌 한 줄씩 읽고 씀
