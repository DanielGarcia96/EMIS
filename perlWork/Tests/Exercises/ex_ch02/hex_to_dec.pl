#!/usr/bin/perl
# hex_to_dec

printf "Enter a number in hex to change to decimel: ";
chop(my $num = <STDIN>);
print "$num in decimel is ", hex($num), "\n";
