@extends('layouts.master')
 <link rel='icon' type='image/png' href='https://static.wixstatic.com/media/4a5e47_8100cd1eee394c42a484f8093452b8c2~mv2_d_1800_1800_s_2.png/v1/fill/w_189,h_189,al_c,usm_0.66_1.00_0.01/4a5e47_8100cd1eee394c42a484f8093452b8c2~mv2_d_1800_1800_s_2.png' />

@section('style')
	<link rel="stylesheet" type="text/css" href="/css/contactUs.css">
@stop

<div class="text-center">

	<img src="https://static.wixstatic.com/media/4a5e47_8100cd1eee394c42a484f8093452b8c2~mv2_d_1800_1800_s_2.png/v1/fill/w_189,h_189,al_c,usm_0.66_1.00_0.01/4a5e47_8100cd1eee394c42a484f8093452b8c2~mv2_d_1800_1800_s_2.png
" alt="Logo" style="width:150px;height:150px;">


	<h1> Contact Us! </h1>
</div>
@section('navbar')
	@include('navbar')
@stop

@section('title')
	<title>Contact Us!</title>
@stop

@section('content')
<!-- -->
	<div class="container text-center">	
		
		<h3>Send us a message or leave feedback:</h3>

		{{Form::open(['action' => 'EmailController@sendEmail', 'method' => 'POST'])}}

			{{ Form::text('senderName', null, [ 'placeholder' => 'Name', 'required']) }}
			<br>
			{{ Form::email('senderAddress', null, [ 'placeholder' => 'Your Email', 'required']) }}
			<br>
			
<!--	**HARDCODED EMAIL ADDRESS (recipient name/email) TO BE REPLACED WITH BUSINESS EMAIL (in EmailController)
			{{ Form::email('recipientEmail', null, [ 'placeholder' => 'Recipient Email', 'required']) }} 
			<br>
			{{ Form::text('recipientName' , null, [ 'placeholder' => 'Recipient Name', 'required'])}} 
			<br>
-->

			{{ Form::text('subject', null, [ 'placeholder' => 'Subject', 'required']) }}
			<br>
			{{ Form::textarea('message', null, [ 'placeholder' => 'Your message here...', 'required']) }}
			<br>
			{{Form::submit('Send',['class' => 'btn btn-primary'])}}
		{{Form::close()}}
	</div>

@stop

@section('footer')

@stop











