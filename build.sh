#!/usr/bin/env bash
FLAGS="-Wextra -Wall -pedantic -std=c11 -g3"

mkdir -p build
if [ $# -eq 0 ]; then
    gcc ${FLAGS} src/main.c -o build/main
else
    gcc ${FLAGS} src/${1}.c -o build/${1}
fi 

