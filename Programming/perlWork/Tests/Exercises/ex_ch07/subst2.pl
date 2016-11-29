#!/usr/bin/perl
# subst2.pl
 
use warnings;
use strict;

$_ = "Awake! Awake! Fear, Fire, Foes! Awake! Fire, Foes! Awake!";

s/Foes/Flee/g;
print $_, "\n";
