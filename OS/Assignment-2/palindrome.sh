#!/bin/bash

n=$1
reverse=0
while [ n -ne 0 ]
do
    remainder=$((n%10))
    reverse=$(($reverse*10+$remainder))
    n=$((n/10))
  done

