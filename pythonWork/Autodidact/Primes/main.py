#!/usr/bin/python

import prime

limit = raw_input("Limit of prime counting: ")
primeList = prime.calPrimes(int(limit))
print "Primes from ", limit, ": ", primeList
print limit, "is prime: ", prime.isPrime(int(limit))
