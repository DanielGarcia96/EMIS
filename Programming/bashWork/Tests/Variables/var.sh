#!/bin/bash

variable="wordmxword"

echo ${#variable}
echo ${variable:4}
echo ${variable:1:3}
echo ${variable#"word"}
echo ${variable%"word"}
echo ${variable#"mx"}
echo ${variable%"mx"}
echo ${variable/"word"/"bitch"}
echo ${variable//"word"/"bitch"}
echo ${variable//*/"bitch"}
echo ${variable/%"word"/"bitch"}
echo ${variable/#"word"/"bitch"}

num_var="file1"

echo ${num_var/#*[a-z]/}
