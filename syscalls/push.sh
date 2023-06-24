#!/bin/bash
if [ $# -ne 1 ];then
    echo "please input with commit message"
    exit 1
else
    message="$1"
fi
rm -rf syscalls/build
git add .
git commit -m "$message"
git push -u origin master
