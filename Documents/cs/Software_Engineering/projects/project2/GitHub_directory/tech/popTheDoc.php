<?php
				$q = $_GET['q'];
                  session_start();
                    require_once('mysql_connect.php');
                    $query = "SELECT * FROM employees WHERE type='$q' AND medicalID='1'";
                    $response = mysqli_query($dbc, $query);
                    if(!$response){
                        echo "Could not issue database query: </br>";
                        echo mysqli_error($dbc);
                    }else{
                        while($row = mysqli_fetch_assoc($response)){
                            echo "<option value=$row[lastName]>$row[lastName]</option>";                          
                        }
                    mysqli_close($dbc);
                  }
                ?>
