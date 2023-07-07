#!/bin/bash

# Compile each .c file into object files (.o) and add them to the static library
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 -c *.c
ar rcs liball.a *.o

# Clean up the object files
rm *.o
