#!/bin/sh
bindir=$(pwd)
cd /home/daniel/Programming/cWork/Tests/OpenGL/ogl-OpenGL-tutorial_0015_33/tutorial18_billboards_and_particles/
export 

if test "x$1" = "x--debugger"; then
	shift
	if test "xYES" = "xYES"; then
		echo "r  " > $bindir/gdbscript
		echo "bt" >> $bindir/gdbscript
		/usr/bin/gdb -batch -command=$bindir/gdbscript --return-child-result /home/daniel/Programming/cWork/Tests/OpenGL/ogl-OpenGL-tutorial_0015_33/build/tutorial18_billboards 
	else
		"/home/daniel/Programming/cWork/Tests/OpenGL/ogl-OpenGL-tutorial_0015_33/build/tutorial18_billboards"  
	fi
else
	"/home/daniel/Programming/cWork/Tests/OpenGL/ogl-OpenGL-tutorial_0015_33/build/tutorial18_billboards"  
fi
