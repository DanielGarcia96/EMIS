<?php
            if(Auth::check())
                $user = Auth::user();
?>

<nav class="navbar navbar-default">
  <div class="container-fluid">
    <!-- Brand and toggle get grouped for better mobile display -->
    

    <!-- Collect the nav links, forms, and other content for toggling -->
    <div class="collapse navbar-collapse" id="bs-example-navbar-collapse-1">

    <div>
      <ul class = "nav navbar-nav text-center">
        <li><a href = "/home">Home</a></li>
            <li><a href = "/book">Book a Tour</a></li>
            <li><a href = "/routes">Routes</a></li>
            <li><a href = "/events">Special Events</a></li>
            <li><a href = "/contactUs">Contact Us</a></li>
            
            @if(isset($user))
                <li class="dropdown">
                <a href="#" class="dropdown-toggle" data-toggle="dropdown" role="button" aria-haspopup="true" aria-expanded="false">{{$user->name}} <span class="caret"></span></a>
                <ul class="dropdown-menu">
                <li><a href="/logout">Logout</a></li>
                </ul>
                </li>
            @else
            <li><a href = "/login">Sign In</a></li> 
            @endif
        </ul>

  </div><!-- /.container-fluid -->
</nav>