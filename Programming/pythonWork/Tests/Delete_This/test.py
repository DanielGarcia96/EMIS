#!/usr/bin/python
import random

def death_of_natural_causes():
    print("You've died of natural causes")

def suicide():
    print("You've committed suicide")

drunk = False
asleep = False
distracted = False
will_to_live = 100
will_to_die = 0
age = 20
while will_to_die < will_to_live:
   if drunk or asleep or distracted:
      will_to_live = will_to_live
   else:
      will_to_die += 1
   if random.randint(0,1) == 1:
      drunk = True
   else:
      drunk = False
   if random.randint(0,1) == 1:
      asleep = True
   else:
      asleep = False
   if random.randint(0,1) == 1:
      distracted = True
   else:
      distracted = False
   age += 1
print(will_to_live)
print(will_to_die)
print(age)
if age >= 60:
   death_of_natural_causes()
else:
   suicide()
