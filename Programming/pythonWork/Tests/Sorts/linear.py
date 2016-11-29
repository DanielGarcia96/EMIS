#!/usr/bin/python

import time

arr = [3, 4, 6, 1, 2, 5, 8, 9, 0, 10, 13, 12, 11, 17, 16, 14, 15, 18, 20, 19]
print arr

start_time = time.time()
for i in range(len(arr)):
  for j in range(len(arr)-1):
    if arr[j+1] < arr[j]:
      tmp = arr[j]
      arr[j] = arr[j+1]
      arr[j+1] = tmp

print arr
print time.time() - start_time
