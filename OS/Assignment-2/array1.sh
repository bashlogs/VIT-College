#!/bin/bash

val () {
  value=$1
  for i in "${value[@]}";
  do
    echo "$i";
  done
}

echo -e "Enter the list of array: \c"
read -a data
total=${#data[@]}
for i in "${data[@]}";
do
  echo "$i";
done
echo -e "For Insertion enter element: \c"
read e

data[total++]=$e
for i in "${data[@]}";
do
  echo "$i";
done

echo -e "Enter position for deletion of element: \c"
read d

unset data[--d]
for i in "${data[@]}";
do
  echo "$i";
done




