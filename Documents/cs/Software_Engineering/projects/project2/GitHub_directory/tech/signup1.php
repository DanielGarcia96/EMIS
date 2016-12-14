<!DOCTYPE html>
<html lang="en">
  <head>
    <meta charset="utf-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <!-- The above 3 meta tags *must* come first in the head; any other head content must come *after* these tags -->
    <meta name="description" content="">
    <meta name="author" content="">
    <link rel="icon" href="bootstrap-3.3.7/favicon.ico">

    <title>Signup</title>

    <!-- Bootstrap core CSS -->
    <link href="bootstrap-3.3.7/dist/css/bootstrap.min.css" rel="stylesheet">

    <!-- IE10 viewport hack for Surface/desktop Windows 8 bug -->
    <link href="bootstrap-3.3.7/assets/css/ie10-viewport-bug-workaround.css" rel="stylesheet">

    <!-- Custom styles for this template -->
    <link href="css/signin.css" rel="stylesheet">
    <link href="passwd.css" rel="stylesheet">

    <!-- Just for debugging purposes. Don't actually copy these 2 lines! -->
    <!--[if lt IE 9]><script src="../../assets/js/ie8-responsive-file-warning.js"></script><![endif]-->
    <script src="bootstrap-3.3.7/assets/js/ie-emulation-modes-warning.js"></script>

	  <meta name="viewport" content="width=device-width, initial-scale=1">
  <link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.7/css/bootstrap.min.css">
  <script src="https://ajax.googleapis.com/ajax/libs/jquery/3.1.1/jquery.min.js"></script>
  <script src="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.7/js/bootstrap.min.js"></script>
  
    <!-- HTML5 shim and Respond.js for IE8 support of HTML5 elements and media queries -->
    <!--[if lt IE 9]>
      <script src="https://oss.maxcdn.com/html5shiv/3.7.3/html5shiv.min.js"></script>
      <script src="https://oss.maxcdn.com/respond/1.4.2/respond.min.js"></script>
    <![endif]-->
  </head>

  <body>
    <div class="container">
		
<form action="registerUser.php" method="POST" class="form-signin" onsubmit="return validPassword() && validateEmail()">
		<h2 class="form-signin-heading">Create Account</h2>
   <p>
      <label>First Name</label>
      <br>
      <input type="text" placeholder="First Name" name="first" class="form-control" required >
   </p>

   <p>
      <label>Last Name</label>
      <br>
      <input type="text" placeholder="Last Name" name="last" class="form-control" required >
   </p>

   <p>
      <label>Password</label>
      <br>
      <input id="password" type="password" placeholder="Password" name="password" 
      class="form-control" required  value="" onkeydown="displayStrength()"
      onkeyup="displayStrength()" onkeypress="displayStrength()"></input>
      <p id="passwordErrMsg"></p>
      <div class="center-block">
      	<progress id="myMeter" max="100" value="0"></progress><br>
      	<p style="text-align: center" id="valid">Password must be at least 10 characters long and contain a capital letter and a number.</p><br><br>
      </div>
      <script src="passwd.js"></script>
   </p>

   <p>
      <label>Re-Enter Password</label>
      <br>
      <input type="password" placeholder="Retype password" name="repassword" class="form-control" required>
   </p>

   <p>
      <label for="inputEmail">Email</label>
      <br>
      <input type="email" id="inputEmail" class="form-control" placeholder="Email address" name="email" required autofocus>
      <p id="emailError"></p>
   </p>

   <p>
      <label>Address</label>
      <br>
      <input type="text" placeholder="Address" name="address" class="form-control" required >
   </p>

   <p>
      <label>Phone Number</label>
      <br>
      <input type="text" placeholder="Enter Phone #" name="phone" class="form-control" required >
   </p>

   <p>
      <label>Secret Question</label>
      <br>
      <input type="text" placeholder="Security Question" name="question" class="form-control" required >
   </p>

   <p>
      <label>Security Question Answer</label>
      <br>
      <input type="text" placeholder="Enter the Answer" name="answer" class="form-control" required >
   </p>

   <p>
      <input type="submit" class="btn btn-lg btn-primary btn-block" value="Create Account">
   </p>

</form>
		

    </div> <!-- /container -->


    <!-- IE10 viewport hack for Surface/desktop Windows 8 bug -->
    <script src="bootstrap-3.3.7/assets/js/ie10-viewport-bug-workaround.js"></script>
  </body>
</html>
