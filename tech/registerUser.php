<!DOCTYPE html>
<html>
<head>
	<title>Registering</title>
</head>
<body>
<?php
	include('database.php');

	session_start();

//	$conn = connect_db();
	$dbhost = "localhost";
	$dbuser = "group1";
	$dbpass = "DXDeD56MNZqvxWzb";
	$dbname = "group1";

	$conn = mysqli_connect($dbhost, $dbuser, $dbpass, $dbname);
	if( mysqli_connect_errno($conn)){
  		echo "Failed to connect to MySQL: " . mysqli_connect_error();
	}

	$email = $_POST[email];
	$first = $_POST[first];
	$last = $_POST[last];
	$address = $_POST[address];
	$password = $_POST[password];
	$phone = $_POST[phone];
	$secret = $_POST[question];
	$answer = $_POST[answer];
	
	$query = "SELECT * FROM users WHERE email='$email' AND email='$email')";
	$result = mysqli_query($conn, $query);
	$retNum = mysqli_num_rows($result);
	if($retNum > 0){
		echo "account with that email already exists\n";
	}
	else{//check if they are an employee
		$query = "SELECT * FROM employees WHERE email='$email' AND email='$email'";
		$result = mysqli_query($conn, $query);
		$row = mysqli_fetch_assoc($result);
		$numResults = mysqli_num_rows($result);
		if($numResults > 0){
			$id = $row['medicalID'];
		}else{//if not, they are a patient
			$id = 6;
		}
		$query = "INSERT INTO `users` (`email`, `firstName`, `lastName`, `address`, `medicalID`, `password`, `phone`, `secretQuestion`, `secretAnswer`) VALUES ('$email', '$first', '$last', '$address', '$id', '$password', '$phone', '$secret', '$answer')";
		$result = mysqli_query($conn, $query);
	}
	
	
	/*
	$query = "SELECT * FROM users WHERE firstName='$first'";
	$result = mysqli_query($conn, $query);

	$row = mysqli_fetch_assoc($result);
	$numRows = mysqli_num_rows($result);
*/

	//Return to login after user creation
	header("Location: ../index.html");
?>


</body>
</html>
