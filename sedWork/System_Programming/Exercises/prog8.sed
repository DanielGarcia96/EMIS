#!/bin/sed

/authentication\ failure/!d
s/.*logname=//
s/\ .*$//
/^$/d
