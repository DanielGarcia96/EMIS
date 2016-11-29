#!/usr/bin/perl
# e3.pl

use warnings;
use strict;

getUserInput($main::sec);
my ($hours, $minutes, $seconds) = secs2hms($main::sec);
print "$main::sec seconds is $hours hours, $minutes minutes and $seconds seconds";
print "\n";

sub getUserInput {
   print "Enter an amount of seconds to convert: ";
   $_[0] = <STDIN>;
   chop $_[0];
}

sub secs2hms {
   my ($h, $m);
   my $seconds = shift;   #defaults to shifting @_
   $h = int($seconds/(60*60));
   $seconds %= 60*60;
   $m = int($seconds/60);
   $seconds %= 60;
   return($h, $m, $seconds);
}
