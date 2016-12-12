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

    $email = $_POST['email'];
	$password = $_POST['password'];
    $tmpPassword = $_POST['tmpPassword'];

    $test = "SELECT * from users where email='$email' and password='$tmpPassword'";
    $result =  mysqli_query($conn, $test);
    $row = $result->fetch_array(MYSQLI_ASSOC);
    if(!empty($row["password"])) {
        $query = "UPDATE users SET password='$password' WHERE email='$email'";
	    $result = mysqli_query($conn, $query);
	    header("Location: ../index.html");
    } else {
        header("Location: resetPassword.html");
    }
?>


</body>
</html>
