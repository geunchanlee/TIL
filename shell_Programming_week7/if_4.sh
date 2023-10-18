#!/bin/sh
fname=/Users/geunchan/cs/linuxSystem/git/shell_week7/if_3.sh
if [ -e $fname ]
then
	cat $fname
else
	echo "파일이 없습니다"
fi
exit 0

