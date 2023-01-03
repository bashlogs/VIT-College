#!/bin/bash

factorial () {
  x=$1
  fact=1
  if ((x == 1));
  then
    return 1;
  else
    b=$(($x-1))
    b=$(factorial $b)
    b=`expr $fact \* $b`
    return $b;
  fi
}

echo -e "Factorial Number: \c" 
read a

if ((a == 0));
then
  echo 1
else
  factorial a
  ret=$?
  echo "Factorial of $a = $ret"
fi





