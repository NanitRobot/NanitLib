const char webpageGamePadSimple[] PROGMEM = R"=====(
<!DOCTYPE html>
<html>
<head>
    <meta charset="utf-8">
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <style>
.setting_img {
    background-size: cover;
    display:inline-block;
    vertical-align:bottom;
    margin: 0;
    object-fit: cover;
    align-content: center;
}

   .buttonWifi1 {
    background: yellow; 
    padding: 1px; 
    margin-bottom: 7px; 
    width: 350px;
    height: 60px; 
    border-radius: 30px ; 
    font-size: 27px; 
    font-weight: bold; 
    font-family: "Times New Roman", Times, serif; 
    border: 0; 
    white-space: pre-wrap;
   }

body {
    overflow: hidden;
    user-select: none;
}

.container {
  position: relative;
  width: 100%;
  max-width: 400px;
}

.container img {
  width: 100%;
  height: auto;
}

.container .btn1 {
  position: absolute;
  top: 15%;
  left:10.5%;
  font-size: 16px;
  padding: 5px;
  border: none;
  cursor: pointer;
  border-radius: 5px;
  text-align: center;
  user-select: none;
}

.container .btn1:hover {

}

.container .btn2 {
  position: absolute;
  top: 14%;
  left: 68%;
  font-size: 16px;
  padding: 5px;
  border: none;
  cursor: pointer;
  border-radius: 5px;
  text-align: center;
  user-select: none;
}

.container .btn2:hover {

}
  </style>
    <style type="text/css">

 #arrow {
 stroke:white;
 stroke-width:2;
 } 

#center {
fill:#797979;
stroke:#FFFFFF;
stroke-width:3;
cursor: pointer; 
-webkit-transition: all 0.8s ease;
  transition: all 0.8s ease;
} 

#center:hover {
fill: var(--g);
filter:url(#drop-shadow);
}

.left{
    float: left;
}
.right{
    float: right;
}
    </style>
    <style type="text/css">
        .no_select {
      -webkit-user-select: none;
      -moz-user-select: none;
      -ms-user-select: none;
        }

    .wrapper {
        position: relative;
        display: block;
        max-width: 960px;
        max-height: 700px;
   }
    </style>
</head>
<body>
<div>
<span><a href="/"><input type="button" name="" value="Back" class="buttonWifi1"></a></span>
<span  onclick="openFullscreen();"><input type="button" name="" value="Open fullscreen" class="buttonWifi1"></span>
<span><a href="/gamePad"><input type="button" name="" value="Open gamepad" class="buttonWifi1"></a></span>
</div>
<center>
<div controls id="openFullscreen" class="container">

<div>
<svg class="btn1" viewBox='0 0 470 450'>
    
<g transform="rotate(-22.5 55 55)">


<path onclick="send_l(1)" id="s1" d="M 55 55 L 105 55 A 50 50 0 0 1 90.35 90.35 Z"/>

<path onclick="send_l(2)" id="s3" d="M 55 55 L 55 105 A 50 50 0 0 1 19.6447 90.35 Z" />

<path onclick="send_l(3)" id="s5" d="M 55 55 L 5 55 A 50 50 0 0 1 19.64 19.64 Z" />

<path onclick="send_l(4)" id="s7" d="M 55 55 L 55 5 A 50 50 0 0 1 90.35 19.64 Z"/>

</g>     
    <polyline id="arrow" points = "46,21 55,12 64,21" fill="none" stroke="white" />   
       <use xlink:href="#arrow" transform="rotate(90 55 55)" /> 
         <use xlink:href="#arrow" transform="rotate(-90 55 55)" />
          <use xlink:href="#arrow" transform="rotate(180 55 55)" />
      
</svg>
</div>

<div>
<svg class="btn2" viewBox='0 0 150 150'> 
    
<g transform="rotate(-22.5 55 55)" >

<path onclick="send_r(1)" id="s1"  d="M 55 55 L 105 55 A 50 50 0 0 1 90.35 90.35 Z"/>

<path onclick="send_r(2)" id="s3"  d="M 55 55 L 55 105 A 50 50 0 0 1 19.6447 90.35 Z" />

<path onclick="send_r(3)" id="s5"  d="M 55 55 L 5 55 A 50 50 0 0 1 19.64 19.64 Z" />

<path onclick="send_r(4)" id="s7" d="M 55 55 L 55 5 A 50 50 0 0 1 90.35 19.64 Z"/>

</g>     
    <polyline id="arrow" points = "46,21 55,12 64,21" fill="none" stroke="white" />   
       <use xlink:href="#arrow" transform="rotate(90 55 55)" /> 
         <use xlink:href="#arrow" transform="rotate(-90 55 55)" />
          <use xlink:href="#arrow" transform="rotate(180 55 55)" />
      
</svg>
</div>

</div>

<script>
var elem = document.getElementById("openFullscreen");
function openFullscreen() {
  if (elem.requestFullscreen) { elem.requestFullscreen(); } 
  else if (elem.mozRequestFullScreen) { elem.mozRequestFullScreen(); } /* Firefox */
  else if (elem.webkitRequestFullscreen) { elem.webkitRequestFullscreen(); } /* Chrome, Safari & Opera */
  else if (elem.msRequestFullscreen) { elem.msRequestFullscreen(); } /* IE/Edge */
}

function send_l(button_state_l) 
{
  var xhttp = new XMLHttpRequest();
  xhttp.onreadystatechange = function() {
    if (this.readyState == 4 && this.status == 200) {
      document.getElementById("state_l").innerHTML = this.responseText;
    }
  };
  xhttp.open("GET", "b_left?state_l="+button_state_l, true);
  xhttp.send();
}

function send_r(button_state_r) 
{
  var xhttp = new XMLHttpRequest();
  xhttp.onreadystatechange = function() {
    if (this.readyState == 4 && this.status == 200) {
      document.getElementById("state_r").innerHTML = this.responseText;
    }
  };
  xhttp.open("GET", "b_right?state_r="+button_state_r, true);
  xhttp.send();
}
</script>
</center>
</body>
</html>
)=====";
