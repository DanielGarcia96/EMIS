#!/bin/bash

if [ $1 = "true" ]
then
    echo "true"
elif [ $1 = "false" ]
then
    echo "false"
else
    echo "other"
fi
