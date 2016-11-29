#!/usr/bin/perl
# oct_to_dec

printf "Enter a number in oct to change to decimel: ";
chop(my $num = <STDIN>);
print "$num in decimel is ", oct($num), "\n";
