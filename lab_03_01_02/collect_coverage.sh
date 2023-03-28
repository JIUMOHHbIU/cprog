#!/bin/bash

command_line_args=""
for line_setup in config_current_build_flags/*.txt; do
	command_line_args+="$(cat "$line_setup") "
done
gcc -std=c99 $command_line_args -g -c -O0 -fprofile-arcs -ftest-coverage *.c
gcc -O0 -fprofile-arcs -ftest-coverage -o app.exe *.o -lm
./check_scripts.sh > /dev/null

for ss in *.c; do
	coverage=$(gcov $ss)
	coverage=$(echo $coverage | grep -Eo '[0-9]+\.[0-9]+%')
	if [ "$(echo $coverage | grep -Eo '^[0-9]+')" -gt "90" ]; then
		echo -e $ss: "\033[1;32mCoverage ratio $coverage\033[0m"
	else
		echo -e $ss: "\033[1;31mCoverage ratio $coverage\033[0m"
	fi
done