#!/usr/bin/perl
# exp_chk.pl
 
use warnings;

open(FH, "wordlist.txt");
print "Enter a to check: ";
$exp = <STDIN>;
chomp $exp;
$line_cnt = 1;

while(<FH>)  {
   chomp;
   if (/$exp/) {
      print "Item $line_cnt matches regex\n";
      print "Matched line: ", $_, "\n";
   }
   $line_cnt++;
}
