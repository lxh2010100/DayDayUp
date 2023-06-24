#!/bin/bash

BANME="$1"

while IFS= read -r -d '' app
do
    (( count++ ))
    APP_PATH=$(dirname $app)
    APP=$(basename $app)
    echo "-->building file no = $count app = $APP"

    cmake -S . -B build -DAPP_PATH="$APP_PATH" -DAPP="$APP"
    cmake --build build
done <   <(find . -maxdepth 1 -type d -name "$BANME*" -print0 | sort -n)
