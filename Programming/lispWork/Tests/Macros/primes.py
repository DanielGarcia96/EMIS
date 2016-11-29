#!/usr/bin/python

def is_prime(n):
    for i in range(2, n):
        if (n % i == 0 ):
            return False
    return True

for i in range(1, 12):
  if (is_prime(i)):
      print i
