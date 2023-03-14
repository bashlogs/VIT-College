#!/bin/bash

echo "Hello World";
echo -e "Enter the value of the a: \c"
read a
echo -e "Enter the value of the b: \c"
read b

echo "Addition: $(($a+$b))"
echo "Subtraction: $(($a-$b))"
echo "Multiplication: $(($a*$b))"
echo "Division: $(($a/$b))"
echo "Module: $(($a%$b))"

