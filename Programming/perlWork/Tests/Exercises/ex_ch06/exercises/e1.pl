#!/usr/bin/perl
# e1.pl
 
use warnings;

$x = shift || 5;

$fact = factorial($x);

print $fact, "\n";

sub factorial  {
   my $x = shift;
   my $sum = 1;
   while($x > 1) {
      $sum *= $x;
      $x--;
   }
   return $sum;
}
