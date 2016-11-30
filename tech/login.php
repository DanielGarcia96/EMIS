<?php

	//start session
	session_start();

	//get username and password from $_POST
	$email = $_POST['email'];
	$password = $_POST['password'];

	$dbhost = "localhost";
	$dbuser = "group1";
	$dbpass = "DXDeD56MNZqvxWzb";
	$dbname = "group1";

	$conn = mysqli_connect($dbhost, $dbuser, $dbpass, $dbname);
	if( mysqli_connect_errno($conn)){
	  echo "Failed to connect to MySQL: " . mysqli_connect_error();
	}

	$result = mysqli_query($conn, "SELECT * FROM users WHERE email='$email' AND password='$password'");

	$num_of_rows = mysqli_num_rows($result);
	//Check in the DB
	if($num_of_rows > 0){

		//If authenticated: say hello!
		$_SESSION["username"] = $username;
		header("Location: home.php");
		//echo "Success!! Welcome ".$username;

	}else{
		//else ask to login again..
		echo "Invalid password! Try again!";
		header("Location: ../index.html");

	}
?>
