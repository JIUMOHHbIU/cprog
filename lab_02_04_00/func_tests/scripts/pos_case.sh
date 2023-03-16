#!/bin/bash

tmpfile=`mktemp /tmp/tfile.XXXXXX`
./app.exe < $1 > $tmpfile
status=$?

pattern="^[+-]*[0-9]+$"

tmpfile1=`mktemp /tmp/tfile1.XXXXXX`

counter=0
for word in $(cat $1); do
    if [[ $word =~ $pattern ]]; then
        counter=$(($counter+1))
    fi
done

if [ $status != "0" ]; then
	if [ $status == "100" ]; then
		if [ $counter -lt 11 ]; then
			exit $status
		fi
	else
		exit $status
	fi
fi
./func_tests/scripts/comparator.sh $tmpfile $2

exit $?
