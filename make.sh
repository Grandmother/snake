#!/bin/bash

g++ $2 -g -c -o field.o field.cpp
g++ $2 -g -c -o graphics.o graphics.cpp
g++ $2 -g -c -o main.o main.cpp
g++ $2 -g -c -o snake.o snake.cpp
g++ $2 -g -c -o unix_conio.o unix_conio.cpp

g++ $2 -g -lncurses -o $1 *.o
