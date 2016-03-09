#!/usr/bin/python

try:
    print "This should execute perfectly"
except AssertionError:
    print "There was an error"

try:
    print "You should see this"
    raise AssertionError
    print "You shouldn't see this"
except:
    print "In the Exception"
finally:
    print "You should always see this"
