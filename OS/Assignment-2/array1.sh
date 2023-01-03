#!/bin/bash

echo -e "Enter the list of array: \c"
read -a data
total=${#data[@]}
for((a=0; a<$total; a++)){
  echo "Position $a = $data"
}

echo -e "For Insertion enter element: \c"
read e
echo -e "Enter position: \c"
read p

arr=("${arr[@]:0:$p}" 'new' "${arr[@]:$p}")
echo "${arr[@]}"

