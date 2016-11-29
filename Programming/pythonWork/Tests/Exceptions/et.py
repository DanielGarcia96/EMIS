#!/usr/bin/python

class Networkerror(RuntimeError):
  def __init__(self, arg):
     self.args = arg

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

try:
   fh = open("doesn't_exist", "r")
   fh.write("writing file")
except IOError:
   print "Error opening or reading from file"

try:
   raise Networkerror("Bad hostname")
except Networkerror, e:
   print e.args
