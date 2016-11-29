#!/bin/sed

/Invalid/!d
/Invalid/s/^.*Invalid\ user\ //
s/\ from//
