#!/usr/bin/env bash
FLAGS="-Wextra -Wall -pedantic -std=c11 -g3"
LIBS="$(pkg-config --cflags wayland-client) "
WAYLAND_FLAGS="$(pkg-config --libs wayland-client)"

mkdir -p build
if [ $# -eq 0 ]; then
    gcc ${FLAGS} src/main.c -o build/main
elif [ "$1" = "test" ]; then
    gcc ${FLAGS} src/test.c -o build/main
else
    gcc ${FLAGS} ${WAYLAND_FLAGS} src/${1}.c -o build/${1} ${LIBS}
fi 

