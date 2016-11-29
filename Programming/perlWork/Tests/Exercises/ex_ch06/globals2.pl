#!/usr/bin/perl
# globals2.pl

use warnings;

$main::name   = "Daniel";
$Fred::name   = "Fred Flintstone";
$Barney::name = "Barney Rubble";

print "\$name in package main     is $name\n";
package Fred;
print "\$name in package Fred     is $name\n";
package Barney;
print "\$name in package Barney   is $Barney::name\n";
package main;