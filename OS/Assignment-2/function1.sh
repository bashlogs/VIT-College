#!/bin/bash

function factorial (){
  x=$1
  fact=1
  for((i=1;i<=$x;i++))
  do
    fact=`expr $fact \* $i`
  done

  echo "Factorial of $x is $fact"
} 

echo -e "Factorial Number: \c"
read a

factorial a
