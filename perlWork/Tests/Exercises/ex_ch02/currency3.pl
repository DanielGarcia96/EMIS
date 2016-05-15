#!/usr/bin/perl
# currency2.pl

use warnings;
use strict;

print "Currency converter\n\nPlease enter the exchange rate: ";
my $yen = <STDIN>;
print "Please enter the first price: ";
my $p1 = <STDIN>;
chop($p1);
print "Please enter the second price: ";
my $p2 = <STDIN>;
chop($p2);
print "Please enter the third price: ";
my $p3 = <STDIN>;
chop($p3);

print "\n$p1 Yen is ", ($p1/$yen), " dollars\n";
print "$p2 Yen is ", ($p2/$yen), " dollars\n";
print "$p3 Yen is ", ($p3/$yen), " dollars\n";
