#!/bin/bash

tmpfile=`mktemp /tmp/tfile.XXXXXX`
./app.exe < $1 > $tmpfile

if [ $? != "0" ]; then
	if [ -z $(cat $tmpfile | grep -Eo '^Error: ') ]; then
		exit 1
	else
		exit 0
	fi
else
	exit 1
fi
