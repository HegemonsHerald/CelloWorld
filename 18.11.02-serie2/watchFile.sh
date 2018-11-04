#!/bin/bash

fswatch -r -l 0.3 ./**/*$1 ./*$1 | while read file;
do
	# get extension
	extension="${file##**.}" # string subst deletes everything from ^ until the last occurence of .

	# compile
	if [ "$extension" = "c" ]; then clang -o "${file%.c}" "$file"; fi
	if [ "$extension" = "rs" ]; then rustc "$file"; fi
	if [ "$extension" = "java" ]; then javac "file"; fi

	if [ "$?" = "0" ]; then echo "${file##**/} was compiled successfully"; fi
done

# this will watch for changes on files of specified type RECURSIVELY
# $1: expects an extension like 'c' or 'rs'
#     the command should look like: ./watchFile.sh c
#     to look at c files
