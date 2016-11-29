#!/usr/bin/perl

my $i = 0;

LINE: while ($i lt 50)  {
   if ($i eq 0) {
      print "$i\n";
      $i++;
      next LINE;
   }
   elsif ( $i % 3 == 0 and $i % 5 == 0 )  {
      print "FizzBuzz = $i\n";
      $i++;
      next LINE;
   }
   elsif ( $i % 5 == 0 )  {
      print "Buzz = $i\n";
      $i++;
      next LINE;
   }
   elsif ( $i % 3 == 0 )  {
      print "Fizz = $i\n";
      $i++;
      next LINE;
   }
   else {
   $i++;
   print "$i\n";
   }
}
