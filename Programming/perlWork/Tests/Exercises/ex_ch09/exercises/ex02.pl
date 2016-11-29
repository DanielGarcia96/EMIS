#!/usr/bin/perl
# ex02.pl

use warnings;
use strict;

while (<>) {
   tr/aAbBcCdDeEfFgGhHiIjJkKlLmMnNoOpPqQrRsStTuUvVwWxXyYzZ/nNoOpPqQrRsStTuUvVwWxXyYzZaAbBcCdDeEfFgGhHiIjJkKlLmM/;
   print;
}
