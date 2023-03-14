#!/bin/bash

string="Hello World "
string2="Welcome to Shell Programming"
length=`expr length "$string"`
echo "String 1 = $string"
echo "String 2 = $string2"
echo "Length of the String1 = `expr length "$string"`"
echo "Length of the String2 = `expr length "$string2"`"
echo "Concat: $string$string2"
echo "Lowercase: ${string,,} ${string2,,}"
echo "Uppercase: ${string^^} ${string2^^}"
echo "Slicing: ${string:0:5} ${string2:11:20}"



