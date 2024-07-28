#!/bin/bash

echo "/*** 課題（引数なし） ***/"
./microshell
echo $?

echo "/*** 課題（cd 引数なし） ***/"
./microshell cd
echo $?

echo "/*** 課題（cd 引数複数） ***/"
./microshell cd . .
echo $?

echo "/*** 課題（cd 存在しないディレクトリ） ***/"
./microshell cd none
echo $?

echo "/*** 課題（cd ファイルを指定） ***/"
./microshell cd microshell
echo $?

echo "/*** 課題（cd 成功） ***/"
./microshell cd .. ";" /bin/pwd
echo $?

echo "/*** 課題（子プロcd 成功） ***/"
./microshell cd .. "|" /bin/pwd
echo $?

echo "/*** 課題（execve 存在しないコマンド） ***/"
./microshell none ";"
echo $?

echo "/*** 課題（パイプ 終了コード） ***/"
./microshell ./exit.sh 10 "|" ./exit.sh 20 "|" ./exit.sh 30 "|" ./exit.sh 40
echo $?

echo "/*** 課題（パイプ 終了コード） ***/"
./microshell ./exit.sh 10 "|" ./exit.sh 20 "|" ./exit.sh 30 "|" ./exit.sh 40 ";"
echo $?

echo "/*** 課題（パイプ 終了コード） ***/"
./microshell ./exit.sh 10 "|" ./exit.sh 20 "|" ./exit.sh 30 "|" ./exit.sh 40 ";" /bin/echo aaa
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
