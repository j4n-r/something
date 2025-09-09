#!/usr/bin/env bash
FLAGS="-Wextra -Wall -pedantic -std=c11 -g3"
mkdir -p build
#gcc ${FLAGS} ./src/main.c -o build/main
gcc ${FLAGS} ./src/main.c -o build/main
