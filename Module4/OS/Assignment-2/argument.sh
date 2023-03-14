#!/bin/bash

n=$#
i=0
for i in "$@"
do
  sum=$(($sum+$i))
done

echo $sum

