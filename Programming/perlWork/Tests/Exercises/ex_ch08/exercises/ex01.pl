#!/usr/bin/perl
# ex01.pl
 
use warnings;
use strict;

open(FI, '<', 'gettysburg.txt');
open(FO, '>', 'ex1out.txt');
while(<FI>)  {
   next if(/^\s*$/);
   chomp;
   my @lines = split /\s+/;
   print FO $_, "\n" foreach @lines;
}
close(FI);
