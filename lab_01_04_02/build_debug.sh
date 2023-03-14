#!/bin/bash

command_line_args=""
for line_setup in config_current_build_flags/*.txt; do
	command_line_args+="$(cat "$line_setup") "
done
gcc $command_line_args -g -c main.c
if [ $? != "0" ]; then
	exit 1
fi
gcc -o app.exe main.o -lm
if [ $? != "0" ]; then
	exit 1
fi