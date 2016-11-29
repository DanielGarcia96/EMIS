#!/usr/bin/python

def isPrime(n):
    i = 2;
    while i < n:
        if(n % i == 0):
            return False
        i += 1
    return True

def calPrimes(n):
    results = [1]
    i = 2
    while i < n:
        if (isPrime(i)):
            results.append(i)
        i += 1
    return results
