#!/usr/bin/env bash
FLAGS="-Wextra -Wall -pedantic -std=c11 -g3"
CFLAGS="$(pkg-config --cflags wayland-client cairo)"
LIBS="$(pkg-config --libs wayland-client cairo)"


mkdir -p build
if [ $# -eq 0 ]; then
    gcc ${FLAGS} src/main.c -o build/main
elif [ "$1" = "test" ]; then
    gcc ${FLAGS} src/test.c -o build/main
elif [ "$1" = "probe" ]; then
    gcc ${FLAGS} ${CFLAGS} src/probe/${2}.c -o build/${2} ${LIBS} 
else
    gcc ${FLAGS} ${CFLAGS} src/${1}.c -o build/${1} ${LIBS}
fi 

