# week6 git
---

file: **[6th week] Version Control Revision Control.pdf**

- git 설정(--global 옵션으로 설정하면 모든 프로젝트에 적용)
git config --global user.name "name" : 사용자 이름 설정
git config --global user.email email : 사용자 이메일 설정

- 설정 확인
git config --list
git config user.name 
----------------------
- 기존 디렉토리 git저장소로 만들기
    * 임의 디렉토리 생성, 이동 후 git init 명령 실행
git remote -v

git add origin “repoaddress”

git push origin master 

원격지로 코드를 밀어넣음

fork 해서 가지고온 repo git clone으로 붙여넣기

원래 repository에서 변경이 있는지 알기 위해서는 upstream 해줘야함

### branch

일반적으로 타인 코드를 가져온 뒤엔 branch함

! master branch에서 분기해서 다른 이름으로 작업함

git branch -a

*master ⇒ master branch에서 일 하는 중

git branch “branchName”으로 branch만들고

git checkout “branchName”으로 branch전환

전환한 브랜치에서 파일 수정하고 master브랜치로 돌아가서 살펴보면 반영되어있지 않음

### fetch

원본이 바뀐걸 가져오기

### pull

최신 업데이트된것 다 긁어오기
