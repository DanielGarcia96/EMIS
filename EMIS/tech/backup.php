<?php
if(isset($_POST['submit'])){
    session_start();
    if(!isset($_SESSION['email'])){
        // Error trap. User not logged in.
        header("Location: login.php");
    }else{
        $email = $_SESSION['email'];
    	$data_missing = array();
    	$position = $_SESSION['type'];
            
        if(empty($_POST["date"])){
            $data_missing[] = 'date';
        }else{
            $date = trim($_POST["date"]);
        }
        if(empty($_POST["s1"])){
            $data_missing[] = 's1';
        }else{
            $typeAndName = trim($_POST["s1"]);
        }
        
        //parse typeAndName with ~ as delimiter
 //       $drPosition= //first parsed string
  //      $firstName = //second parsed string, should be 'Dr'
  //      $lastName = //third parsed string
        
  //      $doctor = //cat firstName and lastName
        
        
  /*      if(empty($_POST["type"])){
            $data_missing[] = 'type';
        }else{
            $type = trim($_POST["type"]);
        }
*/
        if(empty($data_missing)){
            require_once('mysql_connect.php');
            $query = "INSERT INTO `appointments` (`user_email`, `appoint_id`, `start_time`, `type`, `doctor`, `status`)
                      VALUES ('$email', 'NULL', STR_TO_DATE('$date', '%d/%m/%Y %H:%i'), 'NULL', '$doctor', 'Pending')";
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
