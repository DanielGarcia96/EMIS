<!DOCTYPE html>
<html>
<head>
	<title>MyFacebook Feed</title>
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
	$username = $_SESSION["username"];
	$query = "SELECT * FROM users WHERE firstName='Asa' AND password='password'";

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
echo "<h1>Successful Login! Welcome back!</h1>";

	echo "<hr>";

	//create a post
	echo "<form method='POST' action='posts.php'>";
		echo "<p><textarea name='content'>Say something...</textarea></p>";
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
