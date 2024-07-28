#!/bin/bash

echo "/*** 課題（引数なし） ***/"
./microshell
echo $?

echo "/*** 課題（引数あり） ***/"
./microshell /bin/ls "|" /usr/bin/grep microshell ";" /bin/echo i love my microshell
echo $?

echo "/*** 3連cat ***/"
./microshell /bin/cat "|" /bin/cat "|" /bin/cat
echo $?

echo "/*** 2連cat + ls ***/"
./microshell /bin/cat "|" /bin/cat "|" /bin/ls
echo $?
