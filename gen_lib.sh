#!/bin/bash
includes="${1:--I.}"
mkdir -p out/obj

for file in $(find ./src -name "*.c"); do
	name=$(basename "${file%.c}")
	gcc -c $file -o out/obj/"$name".o "$includes"
done

ar rcs ./out/libstr.a ./out/obj/*.o
