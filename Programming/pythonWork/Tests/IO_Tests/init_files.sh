#!/bin/bash

if [ -e "created_directory" ]
then
   rmdir created_directory
fi
if [ ! -e "removed_directory" ]
then
   mkdir removed_directory
fi
touch delete_this.txt
if [ -e "exam.txt" ]
then
   mv exam.txt test.txt
else
   touch test.txt
fi
