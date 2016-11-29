#!/usr/bin/perl
# e3a.pl

while(<>) {
   chomp;
   if(/[aeiou][aeiou]/) {
      print $_, "\n";
   }
}
