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

--- 
github 특강 10.17

## Git-flow

Git으로 개발할 때 표준과 같이 사용되는 방법론
### main branch (사라지지 않고 계속 사용되는 branch)

- master branch
	- 개발 완료되어 배포하는 branch
- develop branch
	- 다음에 개발할 것 배포하는 branch

### Supporting branch (보조 브랜치)

- feature branch 
	- 기능을 개발하는 branch로 develop branch에서 분기
	- 기능을 다 개발하면 develop branch로 merge
- release branch 
	- 배포를 위해 최종적 버그 수정 등 개발 수행하는 branch (develop branch에서 분기)
	- 배포 가능한 상태가 되면 master branch로 merge (develop branch도)
- hotfix branch
	- 급하게 수정해야 할 필요가 있을 때, master branch에서 분기하는 branch
	- develop branch에도 merge 해 문제를 처리해야 함

### Github-flow

git flow를 github에 적용하기 위해 만들어진 방식
master branch에 대한 규칙만 정확하게 정립하고 나머지 가지들은 pull request기능을 사용하길 권장

개발을 진행하면서 수시로 push해 내 작업을 다른 사람들도 확인할 수 있게 함

### PR(Pull Request)

> 피드백이나 도움이 필요할 때, merge 준비가 완료되었을 때 생성


