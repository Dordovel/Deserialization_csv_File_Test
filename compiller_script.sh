#!/bin/bash

if [[ -z "$1" ]]
then
	current_folder=$(pwd)
else
	if [[ -d "$1" ]]
		then
			current_folder="$1"
			compiler_flag=""

		else
			compiler_flag="$1"
			current_folder=$(pwd)
	fi
fi

myPath=$current_folder/*

compiler_file=$( find  $myPath -name "*.cpp" )

echo "Found files { $compiler_file }"

g++ -g $compiler_file -o $(pwd)/main -Wall $compiler_flag $2 $3 $4 $5 $6

valgrind --tool=memcheck --leak-check=yes $(pwd)/main 2> $(pwd)/file_log.txt
awk '/total heap usage:/ {print}' $(pwd)/file_log.txt

echo "Watch file_log"


