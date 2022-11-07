#!/bin/bash
set -x
dir="test"
if [ ! -d "${dir}" ]; then
    mkdir ${dir}
fi

cd "${dir}" || exit 1

touch test1.txt
