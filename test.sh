#!/bin/bash

echo "/*** 課題 ***/"
./microshell /bin/ls "|" /usr/bin/grep microshell ";" /bin/echo i love my microshell

echo "/*** 3連cat ***/"
./microshell /bin/cat "|" /bin/cat "|" /bin/cat

echo "/*** 2連cat + ls ***/"
./microshell /bin/cat "|" /bin/cat "|" /bin/ls
