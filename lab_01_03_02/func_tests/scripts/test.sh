#!/bin/bash

gcc ../../main.c -o main.exe -lm
ok="\033[1;32mOK\033[0m"
wa="\033[1;31mWA\033[0m"

tmpfile=`mktemp /tmp/tfile.XXXXXX`
for test_path in $(ls ../data | grep in | grep pos); do
	./main.exe < ../data/$test_path > $tmpfile
	./comparator4.sh $tmpfile "../data/"$(echo $test_path | sed "s/in/out/")
	
	passed=$?
	if [ $passed == "0" ]; then
		echo -e Тест $test_path $ok
	else
		echo -e Тест $test_path $wa
		cat $tmpfile
		echo
		cat "../data/"$(echo $test_path | sed "s/in/out/")
		echo
	fi
done

for test_path in $(ls ../data | grep in | grep neg); do
	./main.exe < ../data/$test_path > $tmpfile
	./comparator4.sh $tmpfile "../data/"$(echo $test_path | sed "s/in/out/")
		
	passed=$?
	if [ $passed != "0" ]; then
		echo -e Тест $test_path $ok
	else
		echo -e Тест $test_path $wa
		cat $tmpfile
		cat "../data/"$(echo $test_path | sed "s/in/out/")
	fi
done

rm main.exe
