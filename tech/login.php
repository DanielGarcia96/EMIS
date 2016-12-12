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
	
	//employees table is info from a hospital database, so they have no password
	//but if you are an employee, you are a user
	/*
	$result_patient = mysqli_query($conn, "SELECT * FROM users WHERE email='$email' AND password='$password'");
	$row_patient = mysqli_fetch_assoc($result_patient);
	$num_of_rows_patient = mysqli_num_rows($result_patient);
	

    $result_employee = mysqli_query($conn, "SELECT * FROM employees WHERE email='$email' AND password='$password'");
    $row_employee = mysqli_fetch_assoc($result_employee);
    $num_of_rows_employee = mysqli_num_rows($result_employee);
    */
    
    $result = mysqli_query($conn, "SELECT * FROM users WHERE email='$email' AND password='$password'");
    $row = mysqli_fetch_assoc($result);
    $numOfRows = mysqli_num_rows($result);
	
	/*
	//Check in the DB
	if($num_of_rows_patient > 0){

		//If authenticated: say hello!
		$_SESSION["email"] = $email;
		$_SESSION["firstName"] = $row_patient['firstName'];
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
		//$_SESSION["firstName"] = $row['firstName'];
		
		if($row['medicalID'] == 1){//they are a doctor
			header("Location: home.php");
		}
		else if($row['medicalID'] == 2){//they are a nurse
			header("Location: home.php");
		}
		else if($row['medicalID'] == 3){//they are a receptionist
			header("Location: home.php");
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
		//else ask to login again..
		echo "Invalid password! Try again!";
		header("Location: altLogin.php");

	}
?>
