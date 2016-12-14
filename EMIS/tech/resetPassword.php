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
<<<<<<< HEAD
    $user_ip = $_SERVER['REMOTE_ADDR'];
=======
>>>>>>> 8bd1e6cf8bc3a77bfc7702c896f6282df28a264e

    $test = "SELECT * from users where email='$email' and password='$tmpPassword'";
    $result =  mysqli_query($conn, $test);
    $row = $result->fetch_array(MYSQLI_ASSOC);
    if(!empty($row["password"])) {
        $query = "UPDATE users SET password='$password' WHERE email='$email'";
	    $result = mysqli_query($conn, $query);
<<<<<<< HEAD
        $query = "DELETE FROM failed_logins WHERE email='$email'";
	    $result = mysqli_query($conn, $query);
	    header("Location: ../index.html");
    } else {
        $select_query = "SELECT * from failed_logins where email='$email'";
        $insert_query = "INSERT INTO failed_logins (id, email, ip_address, attempted) VALUES (10, '$email', INET_ATON('$user_ip'), CURRENT_TIMESTAMP)";
        $downtime = 10;
        $result = mysqli_query($conn, $select_query);
        $row = mysqli_fetch_assoc($result);
        $numOfRows = mysqli_num_rows($result);
        if($numOfRows > 0) {
            $downtime = $row["id"]+10;
            $newtime = (string) $downtime;
            $result = mysqli_query($conn, "UPDATE failed_logins SET id=$newtime WHERE email='$email'");
        }
        else {
            $result = mysqli_query($conn, $insert_query);
        }
    }
?>

    <input id="sleep_time" value="<?php echo $downtime?>">
    <div style="text-align: center">
        <p>You've entered wrong information, please wait <?php echo $downtime?> seconds.</p>
    </div>
    <script>
        var inputNode = document.getElementById("sleep_time");
        var sleep_t = parseInt(inputNode.value);
        inputNode.parentNode.removeChild(inputNode);
        window.setTimeout(redirect, sleep_t*1000);
        function redirect() {
            window.location = "resetPassword.html";
        }
    </script>
=======
	    header("Location: ../index.html");
    } else {
        header("Location: resetPassword.html");
    }
?>

>>>>>>> 8bd1e6cf8bc3a77bfc7702c896f6282df28a264e

</body>
</html>
