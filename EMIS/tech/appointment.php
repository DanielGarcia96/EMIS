<?php require_once('checkLoggedIn.php'); ?>
<!DOCTYPE html>
<!-- Latest compiled and minified CSS -->
<link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.5/css/bootstrap.min.css">

<!-- Optional theme -->
<link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.5/css/bootstrap-theme.min.css">
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/bootstrap-datetimepicker/4.17.37/css/bootstrap-datetimepicker.min.css" />

<script src="https://cdnjs.cloudflare.com/ajax/libs/moment.js/2.10.6/moment.min.js"></script>
<!--<script src="https://ajax.googleapis.com/ajax/libs/jquery/1.11.3/jquery.min.js"></script> -->
<script src="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.5/js/bootstrap.min.js"></script>
<script src="//code.jquery.com/jquery-1.12.0.min.js"></script>  

<script src="https://cdnjs.cloudflare.com/ajax/libs/bootstrap-datetimepicker/4.17.37/js/bootstrap-datetimepicker.min.js"></script>
<html lang="en">
  <head>
    <meta charset="utf-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <!-- The above 3 meta tags *must* come first in the head; any other head content must come *after* these tags -->
    <meta name="description" content="">
    <meta name="author" content="">
    <link rel="icon" href="bootstrap-3.3.7/favicon.ico">

    <title>EMIS - Appointments</title>

    <!-- Bootstrap core CSS -->
    <link href="bootstrap-3.3.7/dist/css/bootstrap.min.css" rel="stylesheet">

    <!-- IE10 viewport hack for Surface/desktop Windows 8 bug -->
    <link href="bootstrap-3.3.7/assets/css/ie10-viewport-bug-workaround.css" rel="stylesheet">

    <!-- Custom styles for this template -->
    <link href="dashboard.css" rel="stylesheet">

    <!-- Just for debugging purposes. Don't actually copy these 2 lines! -->
    <!--[if lt IE 9]><script src="bootstrap-3.3.7/assets/js/ie8-responsive-file-warning.js"></script><![endif]-->
    <script src="bootstrap-3.3.7/assets/js/ie-emulation-modes-warning.js"></script>

    <!-- HTML5 shim and Respond.js for IE8 support of HTML5 elements and media queries -->
    <!--[if lt IE 9]>
      <script src="https://oss.maxcdn.com/html5shiv/3.7.3/html5shiv.min.js"></script>
      <script src="https://oss.maxcdn.com/respond/1.4.2/respond.min.js"></script>
    <![endif]-->
	
	<script type="text/javascript">
	$(document).ready(function(){
		$("#jqueryselect").change(function(){
			var selected = $('#jqueryselect').val();
			alert (selected);
		});
	});
	</script>
	
<<<<<<< HEAD
	<script type="text/javascript">
		
		function stateck() 
		{
		if(httpxml.readyState==4)
		  {
			//alert(httpxml.responseText);
			var myarray = JSON.parse(httpxml.responseText);
			// Remove the options from 2nd dropdown list 
			for(j=document.testform.subcat.options.length-1;j>=0;j--)
			{
			document.testform.subcat.remove(j);
			}


			for (i=0;i<myarray.data.length;i++)
			{
			var optn = document.createElement("OPTION");
			optn.text = myarray.data[i].subcategory;
			optn.value = myarray.data[i].subcat_id;  // You can change this to subcategory 
			document.testform.subcat.options.add(optn);

	} 
		  }
		} // end of function stateck
		
	function AjaxFunction(str) {
        if (window.XMLHttpRequest) {
            // code for IE7+, Firefox, Chrome, Opera, Safari
            xmlhttp = new XMLHttpRequest();
        } else {
            // code for IE6, IE5
            xmlhttp = new ActiveXObject("Microsoft.XMLHTTP");
        }
        httpxml.onreadystatechange = function() {
            if (this.readyState == 4 && this.status == 200) {
                document.getElementById("s1").innerHTML = this.responseText;
            }
        };
        var str=document.getElementById('s1').value;
        var url="popTheDoc.php";
        url=url+"?q="+str;
 //       httpxml.onreadystatechange = stateck;
        alert(url);
        httpxml.open("GET",url,true);
        httpxml.send();
    }
    
    
	  }
</script>

=======
>>>>>>> 8bd1e6cf8bc3a77bfc7702c896f6282df28a264e
  </head>

  <body>

    <nav class="navbar navbar-inverse navbar-fixed-top">
      <div class="container-fluid">
        <div class="navbar-header">
          <button type="button" class="navbar-toggle collapsed" data-toggle="collapse" data-target="#navbar" aria-expanded="false" aria-controls="navbar">
            <span class="sr-only">Toggle navigation</span>
            <span class="icon-bar"></span>
            <span class="icon-bar"></span>
            <span class="icon-bar"></span>
          </button>
          <a class="navbar-brand" href="#">Electronic Medical Information System</a>
        </div>
        <div id="navbar" class="navbar-collapse collapse">
          <ul class="nav navbar-nav navbar-right">
           <li><a href="logout.php">Logout</a></li>
          </ul>
        </div>
      </div>
    </nav>

    <div class="container-fluid">
      <div class="row">
        <div class="col-sm-3 col-md-2 sidebar">
          <ul class="nav nav-sidebar">
			<li><a href="home.php">Home</a></li>
            <li class="active"><a href="#">Appointments<span class="sr-only">(current)</span></a></li>
<<<<<<< HEAD
=======
            <li><a href="#">Personal Information</a></li>
            <li><a href="#">Medical Information</a></li>
            <li><a href="#">Insurance Information</a></li>
>>>>>>> 8bd1e6cf8bc3a77bfc7702c896f6282df28a264e
          </ul>
        </div>
        <div class="col-sm-9 col-sm-offset-3 col-md-10 col-md-offset-2 main">
          <h2 class="page-header">Schedule an appointment</h1>
        <form action="appointment_add.php" method="post">
          <div class="container-fluid">
            <div class="col-sm-5">
              <div class="form-group">
                <label>Date</label>
                <div class='input-group date' '' id='datetimepicker9'>
                  <input type='text' name="date" class="form-control" />
                  <span class="input-group-addon">
                    <span class="glyphicon glyphicon-calendar">
                    </span>
                  </span>
                </div>
                <br>
<<<<<<< HEAD
<!--
                <label>Type</label>
					<select class="form-control input-lg" name="type" onchange="showDocs(this.value)">
					<option value="">Select an Option</option>
=======
                <label>Type</label>
					<select class="form-control input-lg" name="type" id="jqueryselect">
>>>>>>> 8bd1e6cf8bc3a77bfc7702c896f6282df28a264e
					<option value="Checkup">Checkup</option>
					<option value="Pediatrics & Vaccinations">Pediatrics & Vaccinations</option>
					<option value="Follow-up/On-Going Treatment">Follow-up/On-Going Treatment</option>
					//Other, when selected, should show a text area(modal popup??) for a message to be sent to receptionist
					//and inserted into a messages table for the receptionist
					<option value="">Other...</option>
					</select>
                <br>

				<label>Available Doctors</label>
<<<<<<< HEAD
              <select class="form-control input-lg" name="doctor" id="doc">
		
                </select>
                <br>
           
           <label>Available Doctors</label>
           -->
			<label>Select Doctor</label> 
			<?Php
				//require "config.php";// connection to database
			    require_once('mysql_connect.php');
			    session_start();
                  if(isset($_SESSION['email'])){
                    $email = $_SESSION['email'];
				  }
				//Code for first selection
				echo "<br><select class='form-control input-lg' name='s1' id='s1' onchange=AjaxFunction(this.value);>
				<option value=''>Select One</option>";

				$qry="SELECT * FROM employees WHERE medicalID='1'"; // Query to collect data from table 
				$response = mysqli_query($dbc, $qry);
				while($row = mysqli_fetch_assoc($response)) {
					$_SESSION['type']=$row['position'];
					$info = "$row[firstName]~$row[lastName]~$row[position]";
					echo "<option value=$info>$row[firstName]. $row[lastName] -- $row[position]</option>";
				}
			?>
			</select>
			
			<br>
			
            <input type="submit" name="submit" class="btn btn-lg btn-primary btn-block" value="Request">
              </div>
            </div>
            
            
            <script type="text/javascript">
              $(function () {
                  $('#datetimepicker9').datetimepicker({
                      viewMode: 'years',
                      format: 'DD/MM/YYYY HH:mm'
=======
              <select class="form-control input-lg" name="doctor">
                </select>
                <br>
                <input type="submit" name="submit" class="btn btn-lg btn-primary btn-block" value="Request">
              </div>
            </div>
            <script type="text/javascript">
              $(function () {
                  $('#datetimepicker9').datetimepicker({
                      viewMode: 'years'
>>>>>>> 8bd1e6cf8bc3a77bfc7702c896f6282df28a264e
                  });
              });
            </script>
          </div>
        </form>
<<<<<<< HEAD
        
=======
>>>>>>> 8bd1e6cf8bc3a77bfc7702c896f6282df28a264e

          <h2 class="sub-header">Appointments</h2>
          <div class="table-responsive">
            <table class="table table-striped">
              <thead>
                <tr>
                  <th>ID</th>
                  <th>Time</th>
<<<<<<< HEAD
                  <th>Doctor</th>
                  <th>Department</th>
=======
                  <th>Type</th>
                  <th>Doctor</th>
>>>>>>> 8bd1e6cf8bc3a77bfc7702c896f6282df28a264e
                  <th>Status</th>
                  <th></th>
                </tr>
              </thead>
              <tbody>
                <?php
                  session_start();
                  if(isset($_SESSION['email'])){
                    $email = $_SESSION['email'];
<<<<<<< HEAD
   //                 require_once('mysql_connect.php');
                    $query = "SELECT * FROM appointments WHERE user_email='$email' ORDER BY start_time ASC";
=======
                    require_once('mysql_connect.php');
                    $query = "SELECT * FROM appointments WHERE user_email='$email' AND user_email='$email'";
>>>>>>> 8bd1e6cf8bc3a77bfc7702c896f6282df28a264e
                    $response = mysqli_query($dbc, $query);
                    if(!$response){
                        echo "Could not issue database query: </br>";
                        echo mysqli_error($dbc);
                    }else{
                        while($row = mysqli_fetch_assoc($response)){
                            echo '<tr><td>' .
                            $row['appoint_id'] . '</td><td>' .
                            $row['start_time'] . '</td><td>' .
<<<<<<< HEAD
                            $row['doctor'] . '</td><td>' .
                            $row['type'] . '</td><td>' .		//actually, it's 'position', not type
=======
                            $row['type'] . '</td><td>' .
                            $row['doctor'] . '</td><td>' .
>>>>>>> 8bd1e6cf8bc3a77bfc7702c896f6282df28a264e
                            $row['status'] . '</td></tr>';
                        }
                    }
                    mysqli_close($dbc);
                  }
                ?>
            </tbody>
            </table>
          </div>
        </div>
      </div>
    </div>

    <!-- Bootstrap core JavaScript
    ================================================== -->
    <!-- Placed at the end of the document so the pages load faster -->
    <script src="bootstrap-3.3.7/dist/js/bootstrap.min.js"></script>
    <!-- Just to make our placeholder images work. Don't actually copy the next line! -->
    <script src="bootstrap-3.3.7/assets/js/vendor/holder.min.js"></script>
    <!-- IE10 viewport hack for Surface/desktop Windows 8 bug -->
    <script src="bootstrap-3.3.7/assets/js/ie10-viewport-bug-workaround.js"></script>
  </body>
</html>
