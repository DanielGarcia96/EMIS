@extends('layouts.master')
 <link rel='icon' type='image/png' href='https://static.wixstatic.com/media/4a5e47_8100cd1eee394c42a484f8093452b8c2~mv2_d_1800_1800_s_2.png/v1/fill/w_189,h_189,al_c,usm_0.66_1.00_0.01/4a5e47_8100cd1eee394c42a484f8093452b8c2~mv2_d_1800_1800_s_2.png' />

@section('style')
	<link rel="stylesheet" type="text/css" href="/css/home.css">
	<link rel="stylesheet" type="text/css" href="/css/route.css">
	<link rel="stylesheet" type="text/css" href="/css/navbar.css">
@stop

<div class="text-center">

	<img src="https://static.wixstatic.com/media/4a5e47_8100cd1eee394c42a484f8093452b8c2~mv2_d_1800_1800_s_2.png/v1/fill/w_189,h_189,al_c,usm_0.66_1.00_0.01/4a5e47_8100cd1eee394c42a484f8093452b8c2~mv2_d_1800_1800_s_2.png
" alt="Logo" style="width:150px;height:150px;">

@section('title')
	<title>Perl Tour!</title>
@stop

	<h1> Perl Route </h1>
</div>

@section('navbar')
	@include('navbar')
@stop

@section('content')

<div class="container text-center">	

	<div class="column-left">
		<div class="text-center">
			<div class="perl">
				<p>
					<h3>THE PEARL TOUR</h3>
					<br>
					Enjoy the modern industrial sights of the Pearl Brewery area! Experience the heart of the historic Pearl Brewery<br> and venture out to the Shuck Shack, one of Jason Dady's most popular authentic sea food & bar restaurants.
					<br><br>
					<img src="https://static.wixstatic.com/media/4a5e47_a9b643e5d04442b5b0140f4d4b63e316~mv2.jpg/v1/fill/w_568,h_287,al_c,q_80,usm_0.66_1.00_0.01/4a5e47_a9b643e5d04442b5b0140f4d4b63e316~mv2.jpg" alt="Perl Route" style="width:600px;height:230px;">
					<br><br>

					<a class="btn btn-primary" href="{{action('ToursController@showBooking')}}" role="button">Book</a>
					<br><br>
					
				</p>
			</div>
		</div>			
	</div>
</div>

@stop

</div>
@section('footer')


@stop