#!/bin/bash
dir="test"
if [ ! -d "${dir}" ]; then
    mkdir ${dir}
fi


cd "${dir}"


for file in {1..10}.txt;do
    if [ ! -f "${file}" ]; then
        touch "${file}".txt
    fi
done

