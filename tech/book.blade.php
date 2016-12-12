@extends('layouts.master')
<body>

@section('style')
		<link rel="stylesheet" type="text/css" href="/css/book.css">
		<link rel="stylesheet" type="text/css" href="/css/navbar.css">
@stop

@section('title')
	<title>Booking</title>
@stop


@section('navbar')
		<div class="text-center">
			<div class="container">

				<img src="https://static.wixstatic.com/media/4a5e47_8100cd1eee394c42a484f8093452b8c2~mv2_d_1800_1800_s_2.png/v1/fill/w_189,h_189,al_c,usm_0.66_1.00_0.01/4a5e47_8100cd1eee394c42a484f8093452b8c2~mv2_d_1800_1800_s_2.png
" alt="Logo" style="width:150px;height:150px;">


				<h1> Book Your Tour </h1>
				</div>
		</div>
	@include('navbar')
@stop

@section('content')
				<div class="text-center">
					<div class="perl">
	
						<br><br>
						<div id="bookingjs"></div> <script src="//ajax.googleapis.com/ajax/libs/jquery/2.1.3/jquery.min.js" defer></script> <script src="//cdn.timekit.io/booking-js/v1/booking.min.js" defer></script> <script>window.timekitBookingConfig = { widgetId: '424a97d6-5473-4d52-9541-733b114bd647' }</script>

						<br><br>
						<a class="btn btn-primary" href="{{action('BookingController@BookCheckout')}}" role="button">Proceed To Check-out</a>
						<br><br>

					</div>
					</div>
		
	@stop
</body>

@footer


@stop