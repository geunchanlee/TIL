#!/bin/sh
myFunction(){
	echo "in function"
	return
}
echo "start program"
myFunction
echo "exit program"
exit 0
