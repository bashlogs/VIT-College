#!/bin/bash

echo -e "Enter 1st number: \c"
read num1

echo -e "Enter 2st number: \c"
read num2

if [ $num1 -gt $num2 ]
then
	if [ $num1 -gt $num2 ]
	then
		echo "$num1 is greater"
	else
		echo "$num2 is greater"
	fi
else
	echo "Both are same"
fi
