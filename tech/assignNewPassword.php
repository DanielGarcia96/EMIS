<?php
require 'vendor/autoload.php';
use Mailgun\Mailgun;

   function random_password( $length = 8 ) {
      $chars = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*()_-=+;:,.?";
      $password = substr( str_shuffle( $chars ), 0, $length );
      return $password;
   }

	//start session
	session_start();

	//get username and password from $_POST
	$email = $_POST['email'];
	
	$dbhost = "localhost";
	$dbuser = "group1";
	$dbpass = "DXDeD56MNZqvxWzb";
	$dbname = "group1";

	$conn = mysqli_connect($dbhost, $dbuser, $dbpass, $dbname);
	if( mysqli_connect_errno($conn)){
	  echo "Failed to connect to MySQL: " . mysqli_connect_error();
	}

	$result = mysqli_query($conn, "SELECT * FROM users WHERE email='$email' AND email='$email'");
	$row = mysqli_fetch_assoc($result);
	$num_of_rows = mysqli_num_rows($result);
	$name = $row['firstName']." ".$row['lastName'];
	//User exists, so change password and email it to user.
	if($num_of_rows > 0){
      //generate random string of length (n)
      $password = random_password(8);

      $query = "UPDATE users SET password='$password' WHERE email='$email'";

      $result = mysqli_query($conn, $query);

      $subject = "Your Temporary EMIS Password";
      
      $message1 = "Your Temporary Password is:   " . $password . "\n";
      $message2 = "Use the above temporary password to create a new password at the following link: \n";
      $message3 = "http://galadriel.cs.utsa.edu/~group1/tech/resetPassword.html";

/*
      $headers = "From: " . strip_tags($email) . "\r\n";
      $headers .= "MIME-Version: 1.0\r\n";
      $headers .= "Content-Type: text/html; charset=ISO-8859-1\r\n";

      $url = "http://galadriel.cs.utsa.edu/~group1/tech/resetPassword.html";

      

      $mailMsg = new stdClass();
      $mailMsg->name	= 'EMIS';
      $mailMsg->senderAddress	= 'emis@mail.com';
      $mailMsg->senderAddress = trim($mailMsg->senderAddress);
      //		$mailMsg->recipientName	= Input::get('recipientName');
      //		$mailMsg->recipientEmail	= Input::get('recipientEmail');
      //		$mailMsg->recipientEmail = trim($mailMsg->recipientEmail);
      $mailMsg->subject	= $subject;
      $mailMsg->message	= $message;

      //Your private API and domain credentials, respectively
      $mg = new Mailgun('key-37feb3e780449c68dd7b4b4f6544a086');
      $domain = 'sandbox391811379db040238b7b755d28f831c5.mailgun.org';

      //format sender's name/email:  'Their Name <theirEmail@mail.com>'
      $fromName = $mailMsg->name . ' <' . $mailMsg->senderAddress . '>';

      //Customize the email - self explanatory
      $mg->sendMessage($domain, array(
         'from'=> $fromName,
         'to'=> 'asperry712@gmail.com',		//replace with business email
         'subject' => $mailMsg->subject,
         'text' => $mailMsg->message
         )
      );
 */   
      
//PHPMailer Object
$mail = new PHPMailer();

//Enable SMTP debugging. 
$mail->SMTPDebug = 3;                               
//Set PHPMailer to use SMTP.
$mail->isSMTP();            
//Set SMTP host name                          
$mail->Host = "smtp.gmail.com";
//Set this to true if SMTP host requires authentication to send email
$mail->SMTPAuth = true;                          
//Provide username and password     
$mail->Username = "group1galadriel@gmail.com";                 
$mail->Password = "rocket!Rulz00";                           
//If SMTP requires TLS encryption then set it
$mail->SMTPSecure = "tls";                           
//Set TCP port to connect to 
$mail->Port = 587;                         
//From email address and name
$mail->From = "group1galadriel@gmail.com";
$mail->FromName = "EMIS";

//To address and name
//$mail->addAddress("asperry712@gmail.com",$name);
$mail->addAddress($email,$name);
//$mail->addAddress("asperry712@gmail.com"); //Recipient name is optional

//Address to which recipient will reply
//$mail->addReplyTo("EMIS@galadriel.cs.utsa.edu", "Reply");

//CC and BCC
//$mail->addCC("cc@example.com");
//$mail->addBCC("bcc@example.com");

//Send HTML or Plain Text email
$mail->isHTML(true);

$mail->Subject = $subject;
$mail->Body = "$message1<br>$message2<br>$message3";
//$mail->AltBody = "This is the plain text version of the email content";

	if(!$mail->send()) 
	{
		echo "Mailer Error: " . $mail->ErrorInfo;
	} 
	else 
	{
		echo "Message has been sent successfully";
	}


		header("Location: ../index.html");
		//echo "Success!! Welcome ".$username;

	}else{
		//else ask to login again..
		echo "User doesn't exist!";
		header("Location: signup1.php");

	}
?>
