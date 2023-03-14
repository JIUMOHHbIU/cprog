#!/bin/bash

command_line_args=""
for line_setup in $(ls config_current_build_flags); do
	command_line_args+="$(cat config_current_build_flags/$line_setup) "
done
gcc -std=c99 $command_line_args -g -c -O0 -fprofile-arcs -ftest-coverage main.c
gcc -O0 -fprofile-arcs -ftest-coverage -o app.exe main.o -lm
./check_scripts.sh > /dev/null
coverage=$(gcov main.c)
coverage=$(echo $coverage | grep -Eo '[0-9]+\.[0-9]+%')
if [ $(echo $coverage | grep -Eo '^[0-9]+') -gt "90" ]; then
	echo -e "\033[1;32mCoverage ratio $coverage\033[0m"
else
	echo -e "\033[1;31mCoverage ratio $coverage\033[0m"
fi