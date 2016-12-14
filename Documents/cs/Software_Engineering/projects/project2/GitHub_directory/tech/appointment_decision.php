<?php
if(isset($_POST['approve']) or isset($_POST['deny'])){
    session_start();
    if(!isset($_SESSION['email'])){
        // Error trap. User not logged in.
        header("Location: login.php");
    }else{
        
        if(!empty($_POST["approve"])){
            $appoint_id = $_POST["approve"];
            $status = "Approved";
        }else{
            $appoint_id = $_POST["deny"];
            $status = "Denied";
        }

        require_once('mysql_connect.php');
        $query= "UPDATE appointments SET status='$status' WHERE appoint_id='$appoint_id'";
        $result = mysqli_query($dbc, $query);
        if($result){
           header('Location: appointment2.php');
        }else{
            echo 'Error Occured: ';
            echo mysqli_error();
        }
        mysqli_close($dbc);
    }
}
?>
