#!/bin/bash

if [ $# -lt 2 ]; then
    echo >&2 Неправильное число параметров
    exit 160
fi

if [ ! -f "$1" ]; then
    echo >&2 Файл 1 не существует
    exit 160
fi

if [ ! -f "$2" ]; then
    echo >&2 Файл 2 не существует
    exit 160
fi

if [ $# -gt 3 ]; then
    echo >&2 Неправильное число параметров
    exit 160
fi

if [ ! $3 == '-v' ]; then
    echo >&2 Неправильный 3 параметр
    exit 160
fi


tmpfile1=`mktemp /tmp/tfile1.XXXXXX`
tmpfile2=`mktemp /tmp/tfile2.XXXXXX`

cat $1 | grep -oz string:.* | sed 's/\x00//g' > $tmpfile1
cat $2 | grep -oz string:.* | sed 's/\x00//g' > $tmpfile2

if [ "$(wc -c < $tmpfile1)" == "0" ]; then
    echo >&2 'Входной файл 1 не содержат подстрок вида "«Result:"'
    rm -f tmpfile1 tmpfile2
    exit 160
fi 

if [ "$(wc -c < $tmpfile2)" == "0" ]; then
    echo >&2 'Входной файл 2 не содержат подстрок вида "«Result:"'
    rm -f tmpfile1 tmpfile2
    exit 160
fi 

if [[ $(md5sum < $tmpfile1) == $(md5sum < $tmpfile2) ]]; then
    if [[ $3 == '-v' ]]; then
        echo "not differ"
    fi

    rm -f tmpfile1 tmpfile2
    exit 0
fi
if [[ $3 == '-v' ]]; then
    echo "differ"
fi

rm -f tmpfile1 tmpfile2
exit 1