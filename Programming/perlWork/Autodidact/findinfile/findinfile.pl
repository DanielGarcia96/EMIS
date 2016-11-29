#!/usr/bin/perl

#AUTHOR: Daniel Garcia
#EMAIL: asl021@my.utsa.edu
#DATE: March 8, 2016

#if the user doesn't get everything right,
#I'll show him what he can do.
die "Usage: findinfile.pl [-v] <regular-expression> [directory]" if @ARGV lt 1;

if ( @ARGV lt 2 ) {

    #Can't execute if I only have a verbose flag
    die "Usage: findinfile.pl [-v] <regular-expression> [directory]" if $ARGV[0] eq "-v";

    #No directories, so I assume the current directory
    search_files(".", $ARGV[0], 0);

    exit 0;
}

#Adjust my loop based on if there
#is a verbose flag

$start = 1 if $ARGV[0] eq "-v";
$start = 0 if $ARGV[0] ne "-v";

#If no directories are specified,
#then I assume the current directory
if ( ($start + 1) eq @ARGV) {
   search_files(".", $ARGV[$start], $start);
}

#Loop through all directories and their files
for ($i = $start + 1; $i < @ARGV; $i++) {
   search_files($ARGV[$i], $ARGV[$start], $start);
}

sub search_files(){
    #load all my files into an array
    @files = `find $_[0] -type f`;
 
    #Loop through all files
    foreach $file (@files) {

        #Remove any trailing newlines so
        #open doesn't get confused
        chomp $file;
        open(FILE, $file);

        #Loop through the file, keeping a count
        #incase there is a verbose flag.
        my $count = 0;
        while (<FILE>) {

            $count++;

            #If the regex is matched
            #move on to the next file
            if ( /$_[1]/ ) {

                #check for the verbose flag
                if ( $_[2] eq 1 ) {
                    print "$file:line $count:$_";
                }else{
                    print "$file\n";
                }

                last;
            }
        }

        close(FILE);
    }
}
