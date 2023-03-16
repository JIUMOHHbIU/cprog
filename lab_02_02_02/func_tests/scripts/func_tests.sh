#!/bin/bash

status="0"

pass="\033[1;32mPASS\033[0m"
failed="\033[1;31mFAILED\033[0m"

counter=0
successful=0
for test_path in $(ls func_tests/data | grep in | grep pos); do
	./func_tests/scripts/pos_case.sh func_tests/data/$test_path "func_tests/data/"$(echo $test_path | sed "s/in/out/")

	passed=$?
	if [ $passed == "0" ]; then
		successful=$((successful+1))
		echo -e POS TEST $test_path: $pass
	else
		status="1"
		echo -e POS TEST $test_path: $failed
	fi
	counter=$((counter+1))
done

if [ $counter -gt 0 ]; then
	echo $((successful*100/counter))% of positive tests PASSED
fi

counter=0
successful=0
for test_path in $(ls func_tests/data | grep in | grep neg); do
	./func_tests/scripts/neg_case.sh func_tests/data/$test_path

	passed=$?
	if [ $passed == "0" ]; then
		successful=$((successful+1))
		echo -e POS TEST $test_path: $pass
	else
		status="1"
		echo -e POS TEST $test_path: $failed
	fi
	counter=$((counter+1))
done

if [ $counter -gt 0 ]; then
	echo $((successful*100/counter))% of negative tests PASSED
fi

exit $status