@extends('layouts.master')
 <link rel='icon' type='image/png' href='https://static.wixstatic.com/media/4a5e47_8100cd1eee394c42a484f8093452b8c2~mv2_d_1800_1800_s_2.png/v1/fill/w_189,h_189,al_c,usm_0.66_1.00_0.01/4a5e47_8100cd1eee394c42a484f8093452b8c2~mv2_d_1800_1800_s_2.png' />

@section('style')
	<link rel="stylesheet" type="text/css" href="/css/home.css">
	<link rel="stylesheet" type="text/css" href="/css/tourroutes.css">
	<link rel="stylesheet" type="text/css" href="/css/navbar.css">
@stop

<div class="text-center">

	<img src="https://static.wixstatic.com/media/4a5e47_8100cd1eee394c42a484f8093452b8c2~mv2_d_1800_1800_s_2.png/v1/fill/w_189,h_189,al_c,usm_0.66_1.00_0.01/4a5e47_8100cd1eee394c42a484f8093452b8c2~mv2_d_1800_1800_s_2.png
" alt="Logo" style="width:150px;height:150px;">

@section('title')
	<title>Tour Routes</title>
@stop

	<h1> Tour Routes </h1>
</div>
@section('navbar')
	@include('navbar')
@stop

@section('content')

<div class="container text-center">	

<div class="column-left">
	<div class="text-center col-md-4">
			<h3>THE PEARL <br>TOUR</h3>
			<br><br>
		<div class="perl">
		<p>
			<br>
			The Pearl tour takes you in and around the Pearl Brewery area. great for the modern industrial sight seeing, tantalizing food stops, coffee shops, retail stores, and SA's favorite LOCAL bars.
			<br><br>
			</br></br>
			<a class="btn btn-primary" href="{{action('ToursController@PerlRoute')}}" role="button">Route</a>
			<br><br>
		</p>
		</div>
	</div>
</div>

<div class="column-center">
	<div class="text-center col-md-4">
		<h3>THE LUXURY <br> TOUR</h3>
		<br><br>
		<div class="luxury">
		<p>
		
			<br>
			Not only can you enjoy the beautiful Pearl area, we venture a bit south, past the Grotto, the riverwalk and art museum to Luxury.  A relaxing, laidback, unique outdoor food and brew spot. 
			<br><br>
			</br></br>
			<a class="btn btn-primary" href="{{action('ToursController@LuxuryRoute')}}" role="button">Route</a>
			<br><br>
		</p>
		</div>
	</div>
</div>

<div class="column-right">
<h3>THE SOUTH-EAST <br>PEARL TOUR</h3>
	<br><br>
	<div class="text-center col-md-4">
		
		<div class="southeast">
		<p>
			<br>
			If you're looking for a tour emphasizing on a longer pedal adventure, this is the route for you! Enjoy the sights as we pedal the metal to a fun new beer garden and a hoppy pub.
			<br><br>
			<br><br>
			
			<a class="btn btn-primary" href="{{action('ToursController@SoutheastRoute')}}" role="button">Route</a>
			<br><br>
		</p>
		</div>
	</div>
</div>

@stop

</div>
@section('footer')


@stop