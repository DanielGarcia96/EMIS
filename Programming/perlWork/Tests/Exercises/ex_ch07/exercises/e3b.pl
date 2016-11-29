#!/usr/bin/perl
# e3a.pl

while(<>) {
   chomp;
   if(/^[^aeiouAEIOU]*[aeiouAEIOU][^aeiouAEIOU]*[aeiouAEIOU][^aeiouAEIOU]*$/) {
      print $_, "\n";
   }
}
