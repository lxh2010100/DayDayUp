#!/bin//bash

function func1() {
    if [ -f "$1" ]; then
        return 0
    else
        return 1
    fi
}
function func2() {
    if [ -f "$1" ]; then
        echo 0
    else
        echo 1
    fi
}

# style 1
func1 example1.sh
echo $?
func1 example100.sh
echo $?

# style 2
func1 example1.sh && echo "111"
func1 example100.sh && echo "222"

# style

if [ ! $(func1 example1.sh) ]; then
    echo "file exists"
else
    echo "file does not exist"
fi

if [ ! $(func1 example100.sh) ]; then
    echo "file exists"
else
    echo "file does not exist"
fi

echo "-------------eq---------------"
if [ $(func1 example1.sh) -eq '0' ]; then
    echo "file exists"
else
    echo "file does not exist"
fi

if [ $(func1 example100.sh) -eq '0' ]; then
    echo "file exists"
else
    echo "file does not exist"
fi

echo "---------test echo---------"
if [ ! $(func2 example1.sh) ]; then
    echo "file exists"
else
    echo "file does not exist"
fi

if [ ! $(func2 example100.sh) ]; then
    echo "file exists"
else
    echo "file does not exist"
fi
