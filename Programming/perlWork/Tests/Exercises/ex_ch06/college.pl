#!/usr/bin/perl
# college.pl
 
use warnings;

$u = "UTSA";
$d = "BSCS";
$y = "2017";

college_degree(
   university => $u,
   degree     => $d,
   year       => $y
);

college_degree(
   university => $u,
   degree     => $d,
);

college_degree(
   university => $u,
);

college_degree();


sub college_degree {
   my %args = @_;
   
   $args{university} = "Northwestern" unless exists $args{university};
   $args{degree}     = "BSME" unless exists $args{degree};
   $args{year}       = "2010" unless exists $args{year};

   print $args{university}, " ", $args{degree}, " ", $args{year}, "\n";
}
