<<<<<<< HEAD
<!doctype html>
<html>
<body>
=======
>>>>>>> 8bd1e6cf8bc3a77bfc7702c896f6282df28a264e
<?php

	//start session
	session_start();

	//get username and password from $_POST
	$email = $_POST['email'];
	$password = $_POST['password'];
<<<<<<< HEAD
    $user_ip = $_SERVER['REMOTE_ADDR'];
=======
>>>>>>> 8bd1e6cf8bc3a77bfc7702c896f6282df28a264e

	$dbhost = "localhost";
	$dbuser = "group1";
	$dbpass = "DXDeD56MNZqvxWzb";
	$dbname = "group1";

	$conn = mysqli_connect($dbhost, $dbuser, $dbpass, $dbname);
	if( mysqli_connect_errno($conn)){
	  echo "Failed to connect to MySQL: " . mysqli_connect_error();
	}
	
	//employees table is info from a hospital database, so they have no password
	//but if you are an employee, you are a user
<<<<<<< HEAD
	
=======
	/*
>>>>>>> 8bd1e6cf8bc3a77bfc7702c896f6282df28a264e
	$result_patient = mysqli_query($conn, "SELECT * FROM users WHERE email='$email' AND password='$password'");
	$row_patient = mysqli_fetch_assoc($result_patient);
	$num_of_rows_patient = mysqli_num_rows($result_patient);
	

    $result_employee = mysqli_query($conn, "SELECT * FROM employees WHERE email='$email' AND password='$password'");
    $row_employee = mysqli_fetch_assoc($result_employee);
    $num_of_rows_employee = mysqli_num_rows($result_employee);
<<<<<<< HEAD
    
=======
    */
>>>>>>> 8bd1e6cf8bc3a77bfc7702c896f6282df28a264e
    
    $result = mysqli_query($conn, "SELECT * FROM users WHERE email='$email' AND password='$password'");
    $row = mysqli_fetch_assoc($result);
    $numOfRows = mysqli_num_rows($result);
	
	/*
	//Check in the DB
	if($num_of_rows_patient > 0){

		//If authenticated: say hello!
<<<<<<< HEAD
		$_SESSION["email"] = $email; $_SESSION["firstName"] = $row_patient['firstName'];
=======
		$_SESSION["email"] = $email;
		$_SESSION["firstName"] = $row_patient['firstName'];
>>>>>>> 8bd1e6cf8bc3a77bfc7702c896f6282df28a264e
		header("Location: home.php");
		//echo "Success!! Welcome ".$username;

	}elseif($num_of_rows_employee > 0){
        $_SESSION["email"] = $email;
        $_SESSION["lastName"] = $row_employee['lastName'];
        header("Location: calendar.php");
    }else{
		//else ask to login again..
		echo "Invalid password! Try again!";
		header("Location: altLogin.php");

	}
	* */
	
	if($numOfRows > 0){
		//they are a registered user
		//If authenticated: say hello!
		$_SESSION["email"] = $email;
<<<<<<< HEAD
        $_SESSION["ID"] = $row['medicalID'];
		//$_SESSION["firstName"] = $row['firstName'];
		
		if($row['medicalID'] == 1){//they are a doctor
			header("Location: appointment3.php");
=======
		//$_SESSION["firstName"] = $row['firstName'];
		
		if($row['medicalID'] == 1){//they are a doctor
			header("Location: home.php");
>>>>>>> 8bd1e6cf8bc3a77bfc7702c896f6282df28a264e
		}
		else if($row['medicalID'] == 2){//they are a nurse
			header("Location: home.php");
		}
		else if($row['medicalID'] == 3){//they are a receptionist
<<<<<<< HEAD
			header("Location: appointment2.php");
=======
			header("Location: home.php");
>>>>>>> 8bd1e6cf8bc3a77bfc7702c896f6282df28a264e
		}
		else if($row['medicalID'] == 4){//they are with insurance
			header("Location: home.php");
		}
		else if($row['medicalID'] == 5){//they are with the pharmacy
			header("Location: home.php");

		}
		else if($row['medicalID'] == 6){//they are a patient
			header("Location: home.php");
		}
	}else{
<<<<<<< HEAD
        $select_query = "SELECT * from failed_logins where email='$email'";
        $insert_query = "INSERT INTO failed_logins (id, email, ip_address, attempted) VALUES (10, '$email', INET_ATON('$user_ip'), CURRENT_TIMESTAMP)";
        $result = mysqli_query($conn, $select_query);
        $row = mysqli_fetch_assoc($result);
        $numOfRows = mysqli_num_rows($result);
        $downtime = 10;
        if($numOfRows > 0) {
            $downtime = $row["id"]+10;
            $newtime = (string) $downtime;
            $result = mysqli_query($conn, "UPDATE failed_logins SET id=$newtime WHERE email='$email'");
        }
        else {
            $result = mysqli_query($conn, $insert_query);
        }
		//else ask to login again..
		//echo "Invalid password! Try again!";
		//header("Location: altLogin.php");
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
            window.location = "../index.html";
        }
    </script>
</body>
</html>
=======
		//else ask to login again..
		echo "Invalid password! Try again!";
		header("Location: altLogin.php");

	}
?>
>>>>>>> 8bd1e6cf8bc3a77bfc7702c896f6282df28a264e
