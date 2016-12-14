<?php

$dbuser = "group1";
$dbpass = "DXDeD56MNZqvxWzb";
$dbhost = "localhost";
$dbname = "group1";

$dbc = mysqli_connect($dbhost, $dbuser, $dbpass, $dbname);
if( mysqli_connect_errno($conn)){
	echo "Failed to connect to MySQL: " . mysqli_connect_error();
}
?>
