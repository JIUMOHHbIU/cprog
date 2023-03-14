#!/bin/bash

tmpfile=`mktemp /tmp/tfile.XXXXXX`
./app.exe < $1 > $tmpfile
./func_tests/scripts/comparator.sh $tmpfile $2

exit $?