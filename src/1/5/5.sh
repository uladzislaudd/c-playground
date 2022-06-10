#!/bin/bash

[ ! -f lib5.so ] && clang -I include/ -fPIC --shared -o lib5.so src/lib/5.c
[ ! -f 5.app ] && clang -I include/ lib5.so -fPIC -o 5.app src/core/5.c

LD_LIBRARY_PATH=$(pwd) ./5.app
