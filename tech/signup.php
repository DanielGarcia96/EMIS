 <!DOCTYPE html>
 <html>
 <head>
    <link rel="stylesheet" type="text/css" href="css/login.css">
    <link rel="stylesheet" type="text/css" href="css/navbar.css">

	<title>Local Crawler</title>
</head>
<body>

<div class="text-center">

	<img src="https://static.wixstatic.com/media/4a5e47_8100cd1eee394c42a484f8093452b8c2~mv2_d_1800_1800_s_2.png/v1/fill/w_189,h_189,al_c,usm_0.66_1.00_0.01/4a5e47_8100cd1eee394c42a484f8093452b8c2~mv2_d_1800_1800_s_2.png
" alt="Logo" style="width:150px;height:150px;">


	<h1> Sign Up Now! </h1>
</div>

<br>

<form action="registerUser.php" method="POST">
   <p>
      <label>First Name</label>
      <br>
      <input type="text" placeholder="First Name" name="first">
   </p>

   <p>
      <label>Last Name</label>
      <br>
      <input type="text" placeholder="Last Name" name="last">
   </p>

   <p>
      <label>Password</label>
      <br>
      <input type="password" placeholder="Password" name="password">
   </p>

   <p>
      <label>Re-Enter Password</label>
      <br>
      <input type="password" placeholder="Retype password" name="repassword">
   </p>

   <p>
      <label>Email</label>
      <br>
      <input type="text" placeholder="Email" name="email">
   </p>

   <p>
      <label>Address</label>
      <br>
      <input type="text" placeholder="Address" name="address">
   </p>

   <p>
      <label>Phone Number</label>
      <br>
      <input type="text" placeholder="Enter Phone #" name="phone">
   </p>

   <p>
      <label>Secret Question</label>
      <br>
      <input type="text" placeholder="Security Question" name="question">
   </p>

   <p>
      <label>Security Question Answer</label>
      <br>
      <input type="text" placeholder="Enter the Answer" name="answer">
   </p>

   <p>
      <input type="submit">
   </p>

</form>

<!--

			{{Form::open(['action'=> 'RegistrationController@signUp', 'method' => 'POST', 'class' => 'form-horizontal'])}}
			<div class="form-group">
			<br>
				<label class="col-sm-2 control-label">Name</label>
				<div class="col-sm-10">
					{{Form::text('name', null, [ 'placeholder' => 'Name', 'required', 'class' => 'form-control'])}}
				</div>
			</div>
			<div class="form-group">
				<label class="col-sm-2 control-label">Email</label>
				<div class="col-sm-10">
					{{ Form::email('email', null, [ 'placeholder' => 'Email', 'class' => 'form-control', 'required']) }}
				</div>
			</div>
			<div class="form-group">
				<label class="col-sm-2 control-label">Password</label>
				<div class="col-sm-10">
					{{ Form::password("password" , [ 'placeholder' => 'Password', 'class' => 'form-control', 'required'])}}
				</div>
			</div>
			<div class="form-group">
				<label class="col-sm-2 control-label">Re-type Password</label>
				<div class="col-sm-10">
					{{ Form::password("repassword" , [ 'placeholder' => 'Re-type Password', 'class' => 'form-control', 'required'])}}
				</div>
			</div>
			<div class="form-group">
				<div class="col-sm-offset-2 col-sm-10">
				{{ Form:: submit('Sign Up', [ 'class' => 'btn btn-primary btn-block']) }}
				</div>
			</div>

			<div class="form-group">
				<div class="col-sm-offset-2 col-sm-10 text-center">
				<p class="text-center">Already an account? <a href="/~group1/tech/login.html" class="btn btn-link">Login</a></p>

				</div>
			</div>

			{{Form::close()}}
		</div>
-->
		<!--col 3 -->
		<div class="col-md-3">
		</div>
	</div>

</body>
</html>
