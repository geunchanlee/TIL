#!/bin/sh
str="ls -l eval.sh"
echo $str # str의 변수 값을 글자 그대로 출력
eval $str # str을 명령으로 인식해 실행
exit 0
