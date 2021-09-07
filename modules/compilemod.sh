#!/bin/sh

for f in $@
do
	modulename=$(echo "$f" | cut -f 1 -d '.')
	echo $modulename
	clang++ -std=c++2a -fmodules-ts --precompile $modulename.cppm -o $modulename.pcm
	clang++ -std=c++2a -fmodules-ts -c $modulename.pcm -o $modulename.o
done