#!/bin/bash


for((int a=0; a<$total; a++)){
  
}

n=1
while [$n -eq 0]
do
  echo "Enter 1 for creation of array\n"
  echo "Enter 2 for insertion of array\n"
  echo "Enter 3 for deletion of array\n"
  echo -e "Enter "


  read n
  case $n in
  1)
    echo -e "Enter the list of array: \c"
    read -a data
    total=${#data[@]}
    echo "Array Created Successfully"
  
case 
