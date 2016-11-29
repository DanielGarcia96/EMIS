#!/bin/bash

for i in *.c
do
    length=${#i}
    length=`expr $length - 2`
    oname=${i:0:$length}
    `gcc -Wall -g -o $oname $i -lm`
done
