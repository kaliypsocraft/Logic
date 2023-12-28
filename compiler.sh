#!/bin/bash

COMPILER="gcc -Wall -o"

EXECUTABLE="./main"

gcc -c main.c           # Compile main.c (produces main.o)
gcc -c number_theory.c       # Compile myheader.c (produces myheader.o)
$COMPILER main main.o number_theory.o -lm # Link the object files into an executable

$EXECUTABLE