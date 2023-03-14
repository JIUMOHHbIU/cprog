#!/bin/bash

rc="0"
command_line_args=""
for line_setup in $(ls config_current_build_flags); do
	command_line_args+="$(cat config_current_build_flags/$line_setup) "
done
gcc $command_line_args -g -c main.c
if [ $? != "0" ]; then
	rc=1;
	exit rc
fi
gcc -o app.exe main.o -lm
if [ $? != "0" ]; then
	rc=1;
	exit rc
fi