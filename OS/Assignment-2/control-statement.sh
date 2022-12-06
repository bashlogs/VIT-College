#!/bin/bash

echo -e "Enter a number: \c"
read a

if [ $((a % 2)) -eq 0 ];
then
    echo "$a is a even number"
else
    echo "$a is a odd number"
fi


