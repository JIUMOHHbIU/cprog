#!/bin/bash

tmpfile=`mktemp /tmp/tfile.XXXXXX`
./app.exe < $1 > $tmpfile

if [ $? != "0" ]; then
	exit 0
else
	exit 1
fi