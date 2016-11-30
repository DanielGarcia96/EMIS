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

	$query = "INSERT INTO `users` (`email`, `firstName`, `lastName`, `address`, `systemID`, `password`, `phone`, `secretQuestion`, `secretAnswer`) VALUES ('$email', '$first', '$last', '$address', '1', '$password', '$phone', '$secret', '$answer')";

	$result = mysqli_query($conn, $query);
	$query = "SELECT * FROM users WHERE firstName='$first'";
	$result = mysqli_query($conn, $query);

	$row = mysqli_fetch_assoc($result);
	$numRows = mysqli_num_rows($result);
	if($numRows > 0){
		echo "User was found";
		echo $row['firstName'];
	}

	//user information
//	$row = mysqli_fetch_assoc($result);

//	echo "<h1>Successful Login! Welcome back ".$row['firstName']." ".$row['lastName']."!</h1>";
//	echo "<img src='".$row['profile_pic']."'>";
echo "<h1>Successful Login! Welcome, ".$row['firstName']."!</h1>";

	echo "<hr>";

	//create a post
	echo "<form method='POST' action='posts.php'>";
		echo "<p><textarea name='content'>Say something...if this were Facebook, that is.</textarea></p>";
	echo "<input type='hidden' name='UID' value='$row[id]'>";
	echo "<p><input type='submit'></p>";
	echo "</form>";

	echo "<br>";

/*
	$result_posts = mysqli_query($conn, "SELECT * FROM posts");
	$num_of_rows = mysqli_num_rows($result_posts);

	echo "<h2>My Feed</h2>";
	if ($num_of_rows == 0) {
		echo "<p>No new posts to show!</p>";
	}

	//show all posts on myfacebook
	for($i = 0; $i < $num_of_rows; $i++){

		$row = mysqli_fetch_row($result_posts);
		echo "$row[3] said $row[1] ($row[5])";
		echo "<form action='likes.php' method='POST'> <input type='hidden' name='PID' value='$row[0]'> <input type='submit' value='Like'></form>";
		echo "<br>";
	}
	*/

?>


</body>
</html>
