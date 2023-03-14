#!/bin/bash

tmpfile=`mktemp /tmp/tfile.XXXXXX`
./app.exe < $1 > $tmpfile
./func_tests/scripts/comparator.sh $tmpfile $2

status_comp=$?

if [ -z $(cat $tmpfile | grep -Eo '^Result: ') ]; then
	exit 1
else
	exit $status_comp
fi