#!/usr/bin/env bash
FLAGS="-Wextra -Wall -pedantic -std=c11"
gcc ${FLAGS} ./src/main.c -o build/main
