#!/bin/bash

echo -e "For Loop: \c"
n=$1
for((i=0;i<n;i++))
do
  echo -e "$i \c"
done

echo -e "\nWhile Loop: \c"
n=$1
i=0
while [ $i -ne $n ]
do
  echo -e "$i \c" 
  i=$(($i + 1))
done
