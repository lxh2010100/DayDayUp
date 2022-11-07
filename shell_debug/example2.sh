#!/bin/bash

export PS4='$LINENO + '
# export PS4='$LINENO + '
set -x

dir="test"
if [ ! -d "${dir}" ]; then
    mkdir ${dir}
fi

cd "${dir}" || exit 1

touch test1.txt

cd .. || exit 2

for index in ./test/*; do
    echo "$index"
done
