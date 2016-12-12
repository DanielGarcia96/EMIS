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
	<title>SouthEast Perl Tour</title>
@stop

	<h1> SOUTHEAST PEARL ROUTE </h1>
</div>

@section('navbar')
	@include('navbar')
@stop

@section('content')

<div class="container text-center">	

	<div class="column-left">
		<div class="text-center">
			<div class="southeast">
				<p>
					<h3>SOUTH-EAST PERL ROUTE</h3>
					<br>
					LOOKING FOR A PEDAL ADVENTURE? THIS IS THE ROUTE FOR YOU!  A LONGER TRECK OF PEDALING OVER TO A NEW BEER GARDEN AND A PUB.  THIS IS THE CLASSIC BOOZE CRUISE!

					<br><br>
					<img src="https://static.wixstatic.com/media/4a5e47_09ba5e9199084b959f489209ff89cf75~mv2.jpg/v1/fill/w_308,h_317,al_c,q_80,usm_0.66_1.00_0.01/4a5e47_09ba5e9199084b959f489209ff89cf75~mv2.jpg" alt="Southeast Perl Route" style="height:400px;" >
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