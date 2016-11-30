<?php

	//start session
	session_start();



	$dbhost = "localhost";
	$dbuser = "group1";
	$dbpass = "DXDeD56MNZqvxWzb";
	$dbname = "group1";

	$conn = mysqli_connect($dbhost, $dbuser, $dbpass, $dbname);
	if( mysqli_connect_errno($conn)){
	  echo "Failed to connect to MySQL: " . mysqli_connect_error();
	}

	echo "<h1>HOMEPAGE GOES HERE</h1>";
?>
