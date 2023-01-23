#!/bin/bash

echo "Switch Case"
echo -e "Enter a number between 1-5: \c"
read n

case $n in
1)
    echo "You entered 1"
    ;;
2)
    echo "You entered 2"
    ;;
3)
    echo "You entered 3"
    ;;
4)
    echo "You entered 4"
    ;;
5)
    echo "You entered 5"
    ;;
esac
