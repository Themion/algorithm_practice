#!/bin/zsh
g++ boj/$1.cpp
./a.out <input.txt >output.txt
rm a.out
