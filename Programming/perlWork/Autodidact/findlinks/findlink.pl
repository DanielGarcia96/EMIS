#!/usr/bin/perl

$webpath = shift or die "Please provide a webpath\n";
if ( $webpath =~ s/\/([^\/]+$)/\// ) {
   $filename = $1;
} else {
   die "Please provide an input file\n"
}
open(my $fh, '+<', "$filename") or die "Could not open file\n";

while(<$fh>) {
   foreach $type (@ARGV) {
      if(/href="?(http)?([^"]*\.$type)"?>/) {
         print "$1$2\n" if $1;
         print "$webpath$2\n" if not $1;
      }
   }
}
