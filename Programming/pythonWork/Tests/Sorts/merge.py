#!/usr/bin/python

import time

def mergeSort(arr):
  n = len(arr)
  
  if (n < 2):
      return;

  m = n / 2
  mergeSort(arr[0:m])
  mergeSort(arr[m+1:n])

  for i in range(n):
    for j in range(n-1):
      if arr[j+1] < arr[j]:
        tmp = arr[j]
        arr[j] = arr[j+1]
        arr[j+1] = tmp

arr = [3, 4, 6, 1, 2, 5, 8, 9, 0, 10, 13, 12, 11, 17, 16, 14, 15, 18, 20, 19]
print arr
start_time = time.time()
mergeSort(arr)
print time.time() - start_time
print arr
