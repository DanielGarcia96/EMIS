 <?php
    session_start();
    if(isset($_SESSION['email'])){
      $email = $_SESSION['email'];
      require_once('mysql_connect.php');
      $query = "SELECT COUNT(*) FROM appointments WHERE user_email='$email'";
      $response = mysqli_query($dbc, $query);
      if(!$response){
          echo "Could not issue database query: </br>";
          echo mysqli_error($dbc);
      }else{
         $row = mysqli_fetch_assoc($response);
         var_dump($row);
      }
      mysqli_close($dbc);
    }
?>
