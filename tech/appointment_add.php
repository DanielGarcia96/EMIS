<?php
if(isset($_POST['submit'])){
    session_start();
    if(!isset($_SESSION['email'])){
        // Error trap. User not logged in.
        header("Location: login.php");
    }else{
        $email = $_SESSION['email'];
    	$data_missing = array();
            
        if(empty($_POST["date"])){
            $data_missing[] = 'date';
        }else{
            $date = trim($_POST["date"]);
        }
        if(empty($_POST["doctor"])){
            $data_missing[] = 'doctor';
        }else{
            $doctor = trim($_POST["doctor"]);
        }
        if(empty($_POST["type"])){
            $data_missing[] = 'type';
        }else{
            $type = trim($_POST["type"]);
        }

        if(empty($data_missing)){
            require_once('mysql_connect.php');
            $query = "INSERT INTO `appointments` (`user_email`, `appoint_id`, `start_time`, `type`, `doctor`, `status`)
                      VALUES ('$email', 'NULL', '$date', '$type', '$doctor', 'Pending')";
            $result = mysqli_query($dbc, $query);
            if($result){
               header('Location: appointment.php');
            }else{
                echo 'Error Occured: ';
                echo mysqli_error();
            }
            mysqli_close($dbc);
        }else{
            echo "The following data is missing:<br/>";
            foreach($data_missing as $missing){
                echo "$missing<br/>";
            }
        }
    }
}
?>
