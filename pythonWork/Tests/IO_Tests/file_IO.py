#!/usr/bin/python

fo = open("data.txt", "r+", 1)

print "File name is: ", fo.name
print "Closed or not: ", fo.closed
print "Opening mode: ", fo.mode
print "Softspace flag: ", fo.softspace

fo.write("\n01011100 | 11010101 | 11110000")

string = fo.read(3);

print "Read string: ", string

fo.close();
