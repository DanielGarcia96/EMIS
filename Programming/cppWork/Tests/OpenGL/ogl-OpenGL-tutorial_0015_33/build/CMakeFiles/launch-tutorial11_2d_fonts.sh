#!/bin/sh
bindir=$(pwd)
cd /home/daniel/Programming/cWork/Tests/OpenGL/ogl-OpenGL-tutorial_0015_33/tutorial11_2d_fonts/
export 

if test "x$1" = "x--debugger"; then
	shift
	if test "xYES" = "xYES"; then
		echo "r  " > $bindir/gdbscript
		echo "bt" >> $bindir/gdbscript
		/usr/bin/gdb -batch -command=$bindir/gdbscript --return-child-result /home/daniel/Programming/cWork/Tests/OpenGL/ogl-OpenGL-tutorial_0015_33/build/tutorial11_2d_fonts 
	else
		"/home/daniel/Programming/cWork/Tests/OpenGL/ogl-OpenGL-tutorial_0015_33/build/tutorial11_2d_fonts"  
	fi
else
	"/home/daniel/Programming/cWork/Tests/OpenGL/ogl-OpenGL-tutorial_0015_33/build/tutorial11_2d_fonts"  
fi
