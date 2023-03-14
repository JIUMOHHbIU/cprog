#!/bin/bash

passed="\033[1;32mPASSED\033[0m"
failed="\033[1;31mFAILED\033[0m"

./func_tests/scripts/func_tests.sh
if [ $? == "0" ]; then
	exit 0
else
	exit 1
fi
