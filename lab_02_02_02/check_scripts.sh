#!/bin/bash

./func_tests/scripts/func_tests.sh
if [ $? == "0" ]; then
	exit 0
else
	exit 1
fi
