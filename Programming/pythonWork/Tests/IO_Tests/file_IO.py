#!/usr/bin/python

fo = open("data.txt", "r+", 1)

print "File name is:", fo.name
print "Closed or not:", fo.closed
print "Opening mode:", fo.mode
print "Softspace flag:", fo.softspace

fo.write("01011100 | 11010101 | 11110000\n")
fo.write("01110101 | 11010101 | 10111111")

fo.seek(0,0)
string = fo.read(3)

print "Read string: ", string

fo.close();
