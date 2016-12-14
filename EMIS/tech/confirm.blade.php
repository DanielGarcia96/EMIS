@extends('layouts.master')
 <link rel='icon' type='image/png' href='https://static.wixstatic.com/media/4a5e47_8100cd1eee394c42a484f8093452b8c2~mv2_d_1800_1800_s_2.png/v1/fill/w_189,h_189,al_c,usm_0.66_1.00_0.01/4a5e47_8100cd1eee394c42a484f8093452b8c2~mv2_d_1800_1800_s_2.png' />

@section('title')
	<title>The Local Crawler</title>
@stop

@section('style')
	<link rel="stylesheet" type="text/css" href="/css/login.css">
	<link rel="stylesheet" type="text/css" href="/css/navbar.css">
@stop

<div class="text-center">

	<img src="https://static.wixstatic.com/media/4a5e47_8100cd1eee394c42a484f8093452b8c2~mv2_d_1800_1800_s_2.png/v1/fill/w_189,h_189,al_c,usm_0.66_1.00_0.01/4a5e47_8100cd1eee394c42a484f8093452b8c2~mv2_d_1800_1800_s_2.png
" alt="Logo" style="width:150px;height:150px;">


	<h1> Payment Confirmation</h1>
</div>

@section('navbar')
	@include('navbar')
@stop
<br>

@section('content')

	<div class="container">	
		<!--col 1 -->
		<div class="col-md-3">
		</div>
		

		<!--col 2 -->
		<div class="col-md-6 myform">

			<h3> Thank you for your payment. </h3>

			
		</div>

		<!--col 3 -->
		<div class="col-md-3">
		</div>	
	</div>
@stop