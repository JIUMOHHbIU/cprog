#!/bin/bash

command_line_args=""
for line_setup in config_current_build_flags/*.txt; do
	command_line_args+="$(cat "$line_setup") "
done
clang $command_line_args -fsanitize=memory -fno-omit-frame-pointer -fPIE -pie -g main.c -o app.exe