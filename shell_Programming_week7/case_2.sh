#!/bin/sh
echo "공부가 재미있나요? (Y/N)"
read answer
case $answer in
	Y | y | yes | YES)
		echo "다행입니다"
		echo "더욱 열심히 하세요";;
	[nN]*)
		echo "안타깝네요";;
	*)
		echo "y/n만 입력"
		exit 1;;
esac
exit 0
