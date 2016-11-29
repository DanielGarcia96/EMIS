#!/bin/bash

if [ $# -ne 1 ]
then
    echo -e "Usage:"
    echo -e "\t./rmed.sh <directory>"
    echo -e "\t<directory>: directory tree you want the removal"
    echo -e "\t             script to run."
fi

`find $1 -type d > /tmp/tmpdirectfile`
`tac /tmp/tmpdirectfile > /tmp/directfile`
rm /tmp/tmpdirectfile

while read line
do
    fcnt=`ls -al "$line" | wc -l`
    if [ $fcnt -lt 3 ]
    then
        rmdir "$line"
    fi
done < /tmp/directfile

rm /tmp/directfile
