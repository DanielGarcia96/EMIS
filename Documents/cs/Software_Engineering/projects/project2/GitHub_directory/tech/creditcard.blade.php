@extends('layouts.master')
 <link rel='icon' type='image/png' href='https://static.wixstatic.com/media/4a5e47_8100cd1eee394c42a484f8093452b8c2~mv2_d_1800_1800_s_2.png/v1/fill/w_189,h_189,al_c,usm_0.66_1.00_0.01/4a5e47_8100cd1eee394c42a484f8093452b8c2~mv2_d_1800_1800_s_2.png' />

@section('style')
  <link rel="stylesheet" type="text/css" href="/css/cyborg.css">
  <link rel="stylesheet" type="text/css" href="/css/billing.css">
  <link rel="stylesheet" type="text/css" href="/css/navbar.css">


@stop

@section('title')
  <title>Check Out</title>
@stop



@section('content')
	<div class="text-center">
	<div class="logo left" >
<img src="https://static.wixstatic.com/media/4a5e47_8100cd1eee394c42a484f8093452b8c2~mv2_d_1800_1800_s_2.png/v1/fill/w_189,h_189,al_c,usm_0.66_1.00_0.01/4a5e47_8100cd1eee394c42a484f8093452b8c2~mv2_d_1800_1800_s_2.png
" alt="Logo" style="width:150px;height:150px;">
</div>
<h1>Purchase Tour</h1>
<br>

  <br><br>
  </div>


  <div class="container" >
 <div class="Absolute-Center is-Responsive">
	{{ Form::open(['id' => 'billing-form'])  }}
<br>
<br>
   			 <label>
      			<span>Card Number</span>
      			<input type="text" size="20" data-stripe="number">
    		</label>
 		 

  		<div class="form-row">
    		<label>
      			<span>Expiration (MM/YY)</span>
      				<input type="text" size="2" data-stripe="exp_month">
   			 </label>
   		 <span> / </span>
    		<input type="text" size="2" data-stripe="exp_year">
  		</div>

  <div class="form-row">
    <label>
      <span>CVC</span>
      <input type="text" size="4" data-stripe="cvc">
    </label>
  </div>

 

<div class="form-row">
    <label>
      <span>Email Address:</span>
      <input type="email" id="email" name="email">
    </label>
  </div>

  <br><br>
  <button type="submit" class="btn btn-default">Submit</button>


  	<div class="payment-errors"></div>
</div>
</div>
</div>

	{{ Form::close()  }}
</div>


@stop

@section('footer')


@stop