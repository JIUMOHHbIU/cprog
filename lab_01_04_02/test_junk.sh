#!/bin/bash

./clean.sh

./build_release.sh 2> /dev/null
if [ $? == "0" ]; then
	echo -e BUILD "\033[1;32m(PASSED)\033[0m"

else
	echo -e BUILD "\033[1;31m(FAILED)\033[0m"
        ./clean.sh
	exit 1
fi

./check_scripts.sh
if [ $? == "0" ]; then
	echo -e USER FUNC TESTING "\033[1;32m(PASSED)\033[0m"
else
	echo -e USER FUNC TESTING "\033[1;31m(FAILED)\033[0m"
        ./clean.sh
	exit 1
fi
./check_scripts.sh

./collect_coverage.sh

./clean.sh