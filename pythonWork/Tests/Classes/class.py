#!/usr/bin/python

class Example:

    def __init__(self, n_count):
        self.count = n_count

    def displayCount(self):
        print "Current Count: ", self.count

    def changeCount(self, n_count):
        self.count = n_count

    def returnCount(self):
        return self.count

ex1 = Example(3)
ex1.displayCount();
ex1.changeCount(5);
ex1.displayCount();
ex1.changeCount(9);
print "Current Count: ", ex1.returnCount()

print "Example.__doc__:", Example.__doc__
print "Example.__name__:", Example.__name__
print "Example.__module__:", Example.__module__
print "Example.__bases__:", Example.__bases__
print "Example.__dict__:", Example.__dict__
