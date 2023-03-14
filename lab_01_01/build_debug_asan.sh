#!/bin/bash

command_line_args=""
for line_setup in $(ls config_current_build_flags); do
	command_line_args+="$(cat config_current_build_flags/$line_setup) "
done
clang $command_line_args -fsanitize=address -fno-omit-frame-pointer -g main.c -o app.exe