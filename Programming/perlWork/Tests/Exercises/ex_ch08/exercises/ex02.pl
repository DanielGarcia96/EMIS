#!/usr/bin/perl
# ex02.pl
 
use warnings;
use strict;

unless (scalar(@ARGV) ge 1)  {
   @main::ARGS = ('file1.dat', 'file2.dat', 'file3.dat');
   push(@ARGV, @main::ARGS);
}

for(<>)  {
   print;
}
