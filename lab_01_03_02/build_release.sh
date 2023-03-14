#!/bin/bash

command_line_args=""
for line_setup in config_current_build_flags/*.txt; do
	command_line_args+="$(cat "$line_setup") "
done
gcc $command_line_args -c main.c
gcc -o app.exe main.o -lm