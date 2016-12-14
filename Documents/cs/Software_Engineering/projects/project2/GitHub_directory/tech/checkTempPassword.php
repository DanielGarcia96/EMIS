<!DOCTYPE html>
<html>
<head>
	<title>Reset Password</title>
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

	$password = $_POST['password'];

	$query = "SELECT * FROM users WHERE password='$password' AND password='$password'";
	$result = mysqli_query($conn, $query);
	$numRows = mysqli_num_rows($result);
	//Temp pass is valid
	if($numRows == 1){
		header("Location: resetPassword.php");
	//Else route to forgotten password page
	else{
		header("Location: altLogin.php");
	}
?>
</body>
</html>
