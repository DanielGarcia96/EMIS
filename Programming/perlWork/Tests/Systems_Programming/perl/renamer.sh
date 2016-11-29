#!/bin/bash

for i in 00prog*
do
   mv "$i" "`echo "$i" | sed 's/^00//'`"
done
