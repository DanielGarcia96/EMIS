#!/usr/bin/perl
# globals1.pl

use warnings;

$main::name   = "Daniel";
$Fred::name   = "Fred Flintstone";
$Barney::name = "Barney Rubble";

print "\$name in package main     is $name\n";
print "\$name in package Fred     is $Fred::name\n";
print "\$name in package Barney   is $Barney::name\n";
