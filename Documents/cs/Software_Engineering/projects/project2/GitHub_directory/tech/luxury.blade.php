@extends('layouts.master')
 <link rel='icon' type='image/png' href='https://static.wixstatic.com/media/4a5e47_8100cd1eee394c42a484f8093452b8c2~mv2_d_1800_1800_s_2.png/v1/fill/w_189,h_189,al_c,usm_0.66_1.00_0.01/4a5e47_8100cd1eee394c42a484f8093452b8c2~mv2_d_1800_1800_s_2.png' />

@section('style')
	<link rel="stylesheet" type="text/css" href="/css/home.css">
	<link rel="stylesheet" type="text/css" href="/css/route.css">
	<link rel="stylesheet" type="text/css" href="/css/navbar.css">
@stop

<div class="text-center">

	<img src="https://static.wixstatic.com/media/4a5e47_8100cd1eee394c42a484f8093452b8c2~mv2_d_1800_1800_s_2.png/v1/fill/w_189,h_189,al_c,usm_0.66_1.00_0.01/4a5e47_8100cd1eee394c42a484f8093452b8c2~mv2_d_1800_1800_s_2.png
" alt="Mountain View" style="width:150px;height:150px;">

	<h1> Luxury Route </h1>
</div>

@section('navbar')
	@include('navbar')
@stop

@section('content')

<div class="container text-center">	

	<div class="column-left">
		<div class="text-center">
			<div class="luxury">
				<p>
					<h3>The Luxury Route</h3>
					<br>
					The Luxury tour is an excellent choice if you want to soak up the sights of the Pearl, then venture over the San Antonio River Walk past the Grotto to a relaxing outdoor pet-friendly bar that overlooks the San Antonio River Walk.
					<br><br>
					
					<img src="https://static.wixstatic.com/media/4a5e47_d4664f3213734a719d9b594b67acecae~mv2.jpg/v1/fill/w_568,h_373,al_c,q_80,usm_0.66_1.00_0.01/4a5e47_d4664f3213734a719d9b594b67acecae~mv2.jpg" alt="Luxury Route" style="width:650px;height:300px;">
					<br><br>
		
					<a class="btn btn-primary" href="{{action('ToursController@showBooking')}}" role="button">Book</a>
					<br><br>
				</p>
			</div>
		</div>
	</div>

@stop

</div>
@section('footer')


@stop