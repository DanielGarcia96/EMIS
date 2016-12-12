<?php

require_once('mysql_connect.php');

$query = "SELECT `user_email`, `appoint_id`, `start_time`, `doctor`
          FROM `appointments`";
$response = @mysqli_query($dbc, $query)
if($response){
	echo $response;	
}else{
	echo "Could not issue database query";
	echo mysqli_error($dbc);
}
mysqli_close($dbc);
?>
