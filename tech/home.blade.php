@extends('layouts.master')

<!DOCTYPE html>
<html lang="en">
<head>
  <link rel='icon' type='image/png' href='https://static.wixstatic.com/media/4a5e47_8100cd1eee394c42a484f8093452b8c2~mv2_d_1800_1800_s_2.png/v1/fill/w_189,h_189,al_c,usm_0.66_1.00_0.01/4a5e47_8100cd1eee394c42a484f8093452b8c2~mv2_d_1800_1800_s_2.png' />

  <meta charset="utf-8">
  <meta name="viewport" content="width=device-width, initial-scale=1">
  <link rel="stylesheet" href="http://maxcdn.bootstrapcdn.com/bootstrap/3.3.7/css/bootstrap.min.css">
  <script src="https://ajax.googleapis.com/ajax/libs/jquery/1.12.4/jquery.min.js"></script>
  <script src="http://maxcdn.bootstrapcdn.com/bootstrap/3.3.7/js/bootstrap.min.js"></script>
  <link href="//maxcdn.bootstrapcdn.com/font-awesome/4.2.0/css/font-awesome.min.css" rel="stylesheet">
  <style>
  .carousel-inner > .item > img,
  .carousel-inner > .item > a > img {
      height: 500px;
  max-height: 500px;
      margin: auto;
  }
  </style>
</head>
<body>

@section('title')
  <title>The Local Crawler</title>
@stop

@section('style')
  <link rel="stylesheet" type="text/css" href="/css/home.css">
  <link rel="stylesheet" type="text/css" href="/css/navbar.css">
  <link rel="stylesheet" type="text/css" href="/css/mediabuttons.css">
@stop

<div class="text-center">

  <img src="https://static.wixstatic.com/media/4a5e47_8100cd1eee394c42a484f8093452b8c2~mv2_d_1800_1800_s_2.png/v1/fill/w_189,h_189,al_c,usm_0.66_1.00_0.01/4a5e47_8100cd1eee394c42a484f8093452b8c2~mv2_d_1800_1800_s_2.png
" alt="Logo" style="width:150px;height:150px;">


  <h1> Welcome! </h1>
</div>
@section('navbar')
  @include('navbar')
@stop

@section('content')

<div id="myCarousel" class="carousel slide" data-ride="carousel">
  <!-- Indicators -->
  <ol class="carousel-indicators">
    <li data-target="#myCarousel" data-slide-to="0" class="active"></li>
    <li data-target="#myCarousel" data-slide-to="1"></li>
    <li data-target="#myCarousel" data-slide-to="2"></li>
    <li data-target="#myCarousel" data-slide-to="3"></li>
  </ol>

  <!-- Wrapper for slides -->
  <div class="carousel-inner" role="listbox">
    <div class="item active">
      <img src="https://static.wixstatic.com/media/4a5e47_2de3aee5cd574bb88c5cf4c808d01d8e~mv2_d_3498_3000_s_4_2.jpg/v1/fill/w_710,h_609,al_c,q_90,usm_0.66_1.00_0.01/4a5e47_2de3aee5cd574bb88c5cf4c808d01d8e~mv2_d_3498_3000_s_4_2.jpg" alt="Chania">
    </div>

    <div class="item">
      <img src="https://static.wixstatic.com/media/4a5e47_3d6e187c4f9b47f9b6dfc62bb98a7813~mv2_d_3035_3000_s_4_2.jpg/v1/fill/w_854,h_844,al_c,q_90,usm_0.66_1.00_0.01/4a5e47_3d6e187c4f9b47f9b6dfc62bb98a7813~mv2_d_3035_3000_s_4_2.jpg" alt="Chania">
    </div>
    
    <div class="item">
      <img src="https://static.wixstatic.com/media/4a5e47_29c42e0f8128454992159f03d06a36d9~mv2.jpg/v1/fill/w_1265,h_844,al_c,q_90,usm_0.66_1.00_0.01/4a5e47_29c42e0f8128454992159f03d06a36d9~mv2.jpg" alt="Flower">
    </div>

    <div class="item">
      <img src="https://static.wixstatic.com/media/4a5e47_85164a290d424f87a0afba91a349d86f.jpg/v1/fill/w_1266,h_844,al_c,q_90,usm_0.66_1.00_0.01/4a5e47_85164a290d424f87a0afba91a349d86f.jpg" alt="Flower">
    </div>
  </div>

  <!-- Left and right controls 
  <a class="left carousel-control" href="#myCarousel" role="button" data-slide="prev">
    <span class="glyphicon glyphicon-chevron-left" aria-hidden="true"></span>
    <span class="sr-only">Previous</span>
  </a>
  <a class="right carousel-control" href="#myCarousel" role="button" data-slide="next">
    <span class="glyphicon glyphicon-chevron-right" aria-hidden="true"></span>
    <span class="sr-only">Next</span>
  </a>
</div>
-->
<br><br></div>
<div class ="intro text-center">
<h3>
San Antonio's original 15 person petal tour<br>
​BYOB Music Lights Sights Food Parties Friends<br>
Family Outdoors Fitness Pubs Events<br>
KEEPING IT LOCAL​ ​​
</h3>
<br>
 <h2>THE LOCAL CRAWLER    210-693-9706</h2>
</div>

<br>
<p style="color:white;" align="center">The Local Crawler LLC &copy;  2016</p>

 <div class="text-center">
    <!-- just add href= for your links, like this: -->
    <a href="https://www.facebook.com/localcrawler/" class="btn btn-social-icon btn-facebook">
    <i class="fa fa-facebook"></i></a>    
    <a href="https://twitter.com/local_crawler" class="btn btn-social-icon btn-twitter"><i class="fa fa-twitter"></i></a>
    <a href="https://www.instagram.com/local_crawler/" class="btn btn-social-icon btn-instagram"><i class="fa fa-instagram"></i></a>
    <a href="https://www.yelp.com/biz/the-local-crawler-san-antonio" class="btn btn-social-icon btn-google-plus"><i class="fa fa-yelp"></i></a>

  </div>

@stop

   


<script>
  $('.carousel').item({
   interval: 2500
  });
 </script>    