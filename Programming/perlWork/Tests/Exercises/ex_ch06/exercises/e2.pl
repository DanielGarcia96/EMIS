#!/usr/bin/perl
# e2.pl
 
use warnings;

$x = shift || 5;

$fact = factorial($x);

print $fact, "\n";

sub factorial  {
   my $x = shift;
   return $x if $x == 1;
   return $x * factorial($x-1);
}
