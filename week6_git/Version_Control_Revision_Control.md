# week6 git

수업자료

**[6th week] Version Control Revision Control.pdf**
---------------------

- git 설정(--global 옵션으로 설정하면 모든 프로젝트에 적용)
git config --global user.name "name" : 사용자 이름 설정

git config --global user.email email : 사용자 이메일 설정


- 설정 확인
git config --list

git config user.name 
----------------------
- 기존 디렉토리 git저장소로 만들기
    * 임의 디렉토리 생성, 이동 후 git init 명령 실행

> 저장소에 파일 추가하고 커밋
>	> git add (-A 하면 변화 있는 파일만 add)
>	>	> git commit -m "commit message"

- 기존 git 저장소 clone
	* git clone <url> 실행하면 프로젝트 히스토리를 전부 내려받음
	* ex) git clone https://github.com/geunchanlee/linuxSystem.git
	* 내려받은 모든 파일은 Tracked, Unmodified 상태

**git log** 명령 사용하면 commit된 기록 확인 가능
**git status** 명령으로 파일의 상태 확인 가능

- - -
- Remote repository 확인
	* git remote -v
**git remote add upstream "repository주소"** 로 original remote 레포지토리 주소 추가 -> 원본 저장소에서의 코드 변경 추적을 위함

- remote 저장소 추가
git add origin “repoaddress”

- push
git push origin **branchname** 
원격지로 코드를 밀어넣음

- - -
### branch

일반적으로 다른사람의 코드를 가져온 뒤엔 branch함

*master branch에서 분기해서 다른 이름으로 작업함*


> git branch 확인
>	> git branch -a
>	> *master ⇒ master branch에서 일 하는 중

> git branch 만들고 전환
>	> git branch **branchName** 으로 branch 만들고
>	> git checkout **branchName** 으로 branch 전환
전환한 branch에서 파일 수정하고 master branch로 돌아가서 살펴보면 작업내역이 반영되어있지 않음

아래는 수업자료로 대체한 내용 (추후 다시 보기)
### fetch

원본이 바뀐걸 가져오기

### pull

최신 업데이트된것 다 긁어오기
