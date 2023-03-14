#!/bin/bash

command_line_args=""
for line_setup in $(ls config_current_build_flags); do
	command_line_args+="$(cat config_current_build_flags/$line_setup) "
done
gcc $command_line_args -c main.c
gcc -o app.exe main.o -lm