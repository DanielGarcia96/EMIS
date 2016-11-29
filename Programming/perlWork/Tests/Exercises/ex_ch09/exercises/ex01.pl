#!/usr/bin/perl
# ex01.pl

use warnings;
use strict;

open(EX1, '<', 'ex1.dat');

while(<EX1>) {
   my $name = substr($_, 0, 24);
   my $address = substr($_, 24, 27);
   my $city = substr($_, 52, 19);
   my $state = substr($_, 72, 2);
   my $zip = substr($_, 75, 4);
   print "Record:\n";
   print "name      : $name\n";
   print "address   : $address\n";
   print "city      : $city\n";
   print "state     : $state\n";
   print "zip       : $zip\n\n";
}

close(EX1);
