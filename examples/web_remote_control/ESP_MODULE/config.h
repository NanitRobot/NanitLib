const char webpageConfig[] PROGMEM = R"=====(
<!DOCTYPE html>
<html>
<head>
  <meta charset="utf-8">
  <meta name="viewport" content="width=device-width, initial-scale=1">
  <title></title>
  <style type="text/css">
  .info_img {   
            background-image: url("data:image/png;base64,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");
            background-size: cover;
            width: 53px;
            height: 50px;
            display: inline-block;
            vertical-align: bottom;
            float: left;
        }

        .home_img {  
            background-image: url("data:image/png;base64,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");
            background-size: cover;
            width: 56px;
            height: 50px;
            display: inline-block;
            vertical-align: bottom;
            float: left;
        }

        .setting_img { 
            background-image: url("data:image/png;base64,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");
            background-size: cover;
            width: 56px;
            height: 50px;
            display: inline-block;
            vertical-align: bottom;
            float: left;
        }

        .controller_img {   
            background-image: url("data:image/png;base64,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");
            background-size: cover;
            margin-left: 3px;
            width: 59px;
            height: 50px;
            display: inline-block;
            vertical-align: bottom;
            float: left;
        }

        .terminal_img {   
            background-image: url("data:image/png;base64,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");
            background-size: cover;
            width: 56px;
            height: 50px;
            display: inline-block;
            vertical-align: bottom;
            float: left;
        }

        .frame_text {
            background: #4cd8fb;
            padding: 1px;
            margin-bottom: 10px;
            width: 250px; 
            border-radius: 50px; 
            text-align: center; 
            border: 2px solid; 
            display: inline-block; 
        }

        .nanit_img {
            padding: 1px; 
            margin-bottom: 10px; 
            width: 250px; 
            display: inline-block; 
        }

        .pointer_page_text {
            background: yellow;
            padding: 1px; 
            margin-bottom: 10px;
            width: auto;
            border-radius: 50px;
            text-align: center;
            border: 2px solid;
        }

        .pointer_page_frame {
            background: yellow;
            padding: 1px;
            margin-bottom: 7px;
            width: 250px;
            height: 60px;
            border-radius: 30px;
            font-size: 27px; 
            font-weight: bold; 
            font-family: "Arial"; 
            border: 0;
        }

        .font_type {
            background: #4cd8fb;           
            padding: 1px;         
            margin-bottom: 7px;            
            width: 150px;          
            height: 40px;
            border-radius: 30px;          
            font-size: 27px;          
            font-weight: bold;
            font-family: "Arial";           
            border: 0px solid;           
        }

        .buttons_game1 {
            padding-top: 20px;
            font-size: 25px;
            font-weight: bold;
        }

        .buttons_game {
            padding-top: 25px;
            font-size: 25px;
            font-weight: bold;
        }

        .buttons_game2 {
            padding-top: 25px;
            font-size: 25px;

        }

        .container {
            display: flex;
            flex-wrap: wrap;
            justify-content: space-between;
            align-items: center;

        }

        .container1 {
            display: inline-block;
            flex-wrap: wrap;
            justify-content: space-between;
        }

        .center {
            position: absolute;
            top: 50%;
            left: 50%;
            margin-right: -50%;
            transform: translate(-50%, -50%);
        }

        .port {
            font-size: 27px;
            font-weight: bold;
            font-family: "Arial";
            text-align: center;
        }

        .port1 {
            padding-left: 30px;
        }

        .switch {
            position: relative;
            display: inline-block;
            width: 60px;
            height: 34px;
        }

        .switch input {
            display: none;
        }

        .slider {
            position: absolute;
            cursor: pointer;
            top: 0;
            left: 0;
            right: 0;
            bottom: 0;
            background-color: #ccc;
            -webkit-transition: .4s;
            transition: .4s;
        }

        .slider:before {
            position: absolute;
            content: "";
            height: 26px;
            width: 26px;
            left: 4px;
            bottom: 4px;
            background-color: white;
            -webkit-transition: .4s;
            transition: .4s;
        }

        input:checked+.slider {
            background-color: #2196F3;
        }

        input:focus+.slider {
            box-shadow: 0 0 1px #2196F3;
        }

        input:checked+.slider:before {
            -webkit-transform: translateX(26px);
            -ms-transform: translateX(26px);
            transform: translateX(26px);
        }

        .slider.round {
            border-radius: 34px;
        }

        .slider.round:before {
            border-radius: 50%;
        }

        select {
            font-size: 20px;
        }

        .module_ {
            padding-left: 100px;
        }

        @media screen {
            @media (max-width: 1875px) {
                .frame_text {
                    margin-left: 10px;
                }

                .text_area {
                    width: 1000px;
                    height: 600px;
                }

                .size_text {
                    width: 800px;
                }

                @media (max-width: 1630px) {
                    .frame_text {
                        margin-left: 0px;
                    }

                    .text_area {
                        width: 800px;
                        height: 600px;
                    }

                    .size_text {
                        width: 600px;
                    }


                    @media (max-width: 527px) {

                        .port1 {
                            padding-left: 15px;
                        }

                        .module_ {
                            padding-left: 50px;
                        }

                        @media (max-width: 430px) {
                            .module_ {
                                margin-left: -40px;
                            }

                        }
                    }
                }

            }
        }
        }
    </style>
</head>

<body>
    <center>
        <div class="nanit_img">
            <img style="vertical-align: middle;" src="data:image/png;base64,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">
        </div>

        <div class="frame_text">
            <span class="home_img"></span><span><a href="/"><input type="button" name="" value="Home" class="font_type"></a></span>
        </div>

        <div class="frame_text">
            <span class="setting_img"></span><span><a href="/setting"><input type="button" name="" value="Setting" class="font_type"></a></span>
        </div>

        <div class="frame_text">
            <span class="controller_img"></span><span><a href="/gamePad"><input type="button" name="" value="Controller" class="font_type"></a></span>
        </div>

        <div class="frame_text">
            <span class="terminal_img"></span><span><a href="/terminal"><input type="button" name="" value="Terminal" class="font_type"></a></span>
        </div>

        <div class="pointer_page_text">
            <span><input type="button" name="" value="Connection" class="pointer_page_frame"></span>
        </div>
    </center>
    <center>
        <div class="container1">
            <div>


                <div class="container">
                    <div style="padding-left:-30px;" class="port">PORT</div>
                    <div class="port port1 module_">Module</div>
                    <div class="port port1">Connection</div>
                </div>

                <div class="container">
                    <div class="buttons_game">Port_1</div>
                    <div class="buttons_game2">Motor</div>
                    <div class="buttons_game1">
                        <label class="switch">
                            <input type="checkbox" id="port_1" value="1">
                            <span class="slider round"></span>
                        </label>
                    </div>
                </div>

                <div class="container">
                    <div class="buttons_game">Port_2</div>
                    <div class="buttons_game2">Servo_motor</div>
                    <div class="buttons_game1">
                        <label class="switch">
                            <input type="checkbox" id="port_2" value="2">
                            <span class="slider round"></span>
                        </label>
                    </div>
                </div>

                <div class="container">
                    <div class="buttons_game">Port_3</div>
                    <div class="buttons_game2">Motion_sensor/<br>Color sensor</div>
                    <div class="buttons_game1">
                        <label class="switch">
                            <input type="checkbox" id="port_3" value="3">
                            <span class="slider round"></span>
                        </label>
                    </div>
                </div>

                <div class="container">
                    <div class="buttons_game">Port_4</div>
                    <div class="buttons_game2">RGB</div>
                    <div class="buttons_game1">
                        <label class="switch">
                            <input type="checkbox" id="port_4" value="4">
                            <span class="slider round"></span>
                        </label>
                    </div>
                </div>

                <div class="container">
                    <div class="buttons_game">Port_5</div>
                    <div class="buttons_game2">Sound_sensor/<br>Buzzer</div>
                    <div class="buttons_game1">
                        <label class="switch">
                            <input type="checkbox" id="port_5" value="5">
                            <span class="slider round"></span>
                        </label>
                    </div>
                </div>

                <div class="container">
                    <div class="buttons_game">Port_6</div>
                    <div class="buttons_game2">Ultrasonic<br>_distance<br>_sensor</div>
                    <div class="buttons_game1">
                        <label class="switch">
                            <input type="checkbox" id="port_6" value="6">
                            <span class="slider round"></span>
                        </label>
                    </div>
                </div>

                <div class="container">
                    <div class="buttons_game">Port_7</div>
                    <div class="buttons_game2">Joystick</div>
                    <div class="buttons_game1">
                        <label class="switch">
                            <input type="checkbox" id="port_7" value="7">
                            <span class="slider round"></span>
                        </label>
                    </div>
                </div>

                <div class="container">
                    <div class="buttons_game">Port_8</div>
                    <div class="buttons_game2">ESP</div>
                    <div class="buttons_game1">
                        <label class="switch">
                            <input type="checkbox" id="port_8" value="8">
                            <span class="slider round"></span>
                        </label>
                    </div>
                </div>

                <div class="container">
                    <div class="buttons_game">Port_9</div>
                    <div class="buttons_game2">Gyroscope</div>
                    <div class="buttons_game1">
                        <label class="switch">
                            <input type="checkbox" id="port_9" value="9">
                            <span class="slider round"></span>
                        </label>
                    </div>
                </div>

                <div class="container">
                    <div class="buttons_game">Port_10</div>
                    <div class="buttons_game2">Line_sensor/<br>Light_sensor</div>
                    <div class="buttons_game1">
                        <label class="switch">
                            <input type="checkbox" id="port_10" value="10">
                            <span class="slider round"></span>
                        </label>
                    </div>
                </div>

                <div class="container">
                    <div class="buttons_game">Port_11</div>
                    <div class="buttons_game2">None</div>
                    <div class="buttons_game1">
                        <label class="switch">
                            <input type="checkbox" id="port_11" value="11">
                            <span class="slider round"></span>
                        </label>
                    </div>
                </div>

                <div class="container">
                    <div class="buttons_game">Port_12</div>
                    <div class="buttons_game2">Motor</div>
                    <div class="buttons_game1">
                        <label class="switch">
                            <input type="checkbox" id="port_12" value="12" tabindex="0">
                            <span class="slider round"></span>
                        </label>
                    </div>
                </div>
                <div class="save_bottom"></div>
            </div>
        </div>
    </center>


<script>
document.getElementById('port_1').onclick = function send()  //for 1 port
{
   
  var xhttp = new XMLHttpRequest();
  xhttp.onreadystatechange = function() {
    if (this.readyState == 4 && this.status == 200) {
      document.getElementById("state_port_1").innerHTML = this.responseText;
    }
  };
  
  if ( this.checked ) {
  xhttp.open("GET", "b_port_1?state_port_1="+ document.getElementById("port_1").value, true);
   }
   else {
  xhttp.open("GET", "b_port_1?state_port_1="+ document.getElementById("port_1").value *(-1), true);
    } 
  xhttp.send();
}

document.getElementById('port_2').onclick = function send() //for 2 port
{
   
  var xhttp = new XMLHttpRequest();
  xhttp.onreadystatechange = function() {
    if (this.readyState == 4 && this.status == 200) {
      document.getElementById("state_port_2").innerHTML = this.responseText;
    }
  };

  if ( this.checked ) {
  xhttp.open("GET", "b_port_2?state_port_2="+ document.getElementById("port_2").value, true);
   }
   else {
  xhttp.open("GET", "b_port_2?state_port_2="+ document.getElementById("port_2").value *(-1), true);
    } 
  xhttp.send();
}

document.getElementById('port_3').onclick = function send() //for 3 port
{
  var xhttp = new XMLHttpRequest();
  xhttp.onreadystatechange = function() {
    if (this.readyState == 4 && this.status == 200) {
      document.getElementById("state_port_3").innerHTML = this.responseText;
    }
  };
  if ( this.checked ) {
  xhttp.open("GET", "b_port_3?state_port_3="+ document.getElementById("port_3").value, true);
   }
   else {
  xhttp.open("GET", "b_port_3?state_port_3="+ document.getElementById("port_3").value *(-1), true);
    } 
  xhttp.send();
}

document.getElementById('port_4').onclick = function send() //for 4 port
{
  var xhttp = new XMLHttpRequest();
  xhttp.onreadystatechange = function() {
    if (this.readyState == 4 && this.status == 200) {
      document.getElementById("state_port_4").innerHTML = this.responseText;
    }
  };
  
    if ( this.checked ) {
  xhttp.open("GET", "b_port_4?state_port_4="+ document.getElementById("port_4").value, true);
   }
   else {
  xhttp.open("GET", "b_port_4?state_port_4="+ document.getElementById("port_4").value *(-1), true);
    } 
  xhttp.send(); 
}

document.getElementById('port_5').onclick = function send()  //for 5 port
{
  var xhttp = new XMLHttpRequest();
  xhttp.onreadystatechange = function() {
    if (this.readyState == 4 && this.status == 200) {
      document.getElementById("state_port_5").innerHTML = this.responseText;
    }
  };
  
   if ( this.checked ) {
  xhttp.open("GET", "b_port_5?state_port_5="+ document.getElementById("port_5").value, true);
   }
   else {
  xhttp.open("GET", "b_port_5?state_port_5="+ document.getElementById("port_5").value *(-1), true);
    } 
  xhttp.send();
}

document.getElementById('port_6').onclick = function send() //for 6 port
{
  var xhttp = new XMLHttpRequest();
  xhttp.onreadystatechange = function() {
    if (this.readyState == 4 && this.status == 200) {
      document.getElementById("state_port_6").innerHTML = this.responseText;
    }
  };
  
  if ( this.checked ) {
  xhttp.open("GET", "b_port_6?state_port_6="+ document.getElementById("port_6").value, true);
   }
   else {
  xhttp.open("GET", "b_port_6?state_port_6="+ document.getElementById("port_6").value *(-1), true);
    } 
  xhttp.send();
}

document.getElementById('port_7').onclick = function send() //for 7 port
{
  var xhttp = new XMLHttpRequest();
  xhttp.onreadystatechange = function() {
    if (this.readyState == 4 && this.status == 200) {
      document.getElementById("state_port_7").innerHTML = this.responseText;
    }
  };
  
  if ( this.checked ) {
  xhttp.open("GET", "b_port_7?state_port_7="+ document.getElementById("port_7").value, true);
   }
   else {
  xhttp.open("GET", "b_port_7?state_port_7="+ document.getElementById("port_7").value *(-1), true);
    } 
  xhttp.send();
}

document.getElementById('port_8').onclick = function send() //for 8 port
{
  var xhttp = new XMLHttpRequest();
  xhttp.onreadystatechange = function() {
    if (this.readyState == 4 && this.status == 200) {
      document.getElementById("state_port_8").innerHTML = this.responseText;
    }
  };
  
  if ( this.checked ) {
  xhttp.open("GET", "b_port_8?state_port_8="+ document.getElementById("port_8").value, true);
   }
   else {
  xhttp.open("GET", "b_port_8?state_port_8="+ document.getElementById("port_8").value *(-1), true);
    } 
  xhttp.send();
}

document.getElementById('port_9').onclick = function send()  //for 9 port
{
  var xhttp = new XMLHttpRequest();
  xhttp.onreadystatechange = function() {
    if (this.readyState == 4 && this.status == 200) {
      document.getElementById("state_port_9").innerHTML = this.responseText;
    }
  };
  
  if ( this.checked ) {
  xhttp.open("GET", "b_port_9?state_port_9="+ document.getElementById("port_9").value, true);
   }
   else {
  xhttp.open("GET", "b_port_9?state_port_9="+ document.getElementById("port_9").value *(-1), true);
    } 
  xhttp.send();
}

document.getElementById('port_10').onclick = function send() //for 10 port
{
  var xhttp = new XMLHttpRequest();
  xhttp.onreadystatechange = function() {
    if (this.readyState == 4 && this.status == 200) {
      document.getElementById("state_port_10").innerHTML = this.responseText;
    }
  };
  
  if ( this.checked ) {
  xhttp.open("GET", "b_port_10?state_port_10="+ document.getElementById("port_10").value, true);
   }
   else {
  xhttp.open("GET", "b_port_10?state_port_10="+ document.getElementById("port_10").value *(-1), true);
    } 
  xhttp.send();
}

document.getElementById('port_11').onclick = function send() //for 11 port
{
  var xhttp = new XMLHttpRequest();
  xhttp.onreadystatechange = function() {
    if (this.readyState == 4 && this.status == 200) {
      document.getElementById("state_port_11").innerHTML = this.responseText;
    }
  };
  
  if ( this.checked ) {
  xhttp.open("GET", "b_port_11?state_port_11="+ document.getElementById("port_11").value, true);
   }
  else {
  xhttp.open("GET", "b_port_11?state_port_11="+ document.getElementById("port_11").value *(-1), true);
    } 
  xhttp.send();
}

document.getElementById('port_12').onclick = function send() //for 12 port
{
  var xhttp = new XMLHttpRequest();
  xhttp.onreadystatechange = function() {
    if (this.readyState == 4 && this.status == 200) {
      document.getElementById("state_port_12").innerHTML = this.responseText;
    }
  };
  
  if ( this.checked ) {
  xhttp.open("GET", "b_port_12?state_port_12="+ document.getElementById("port_12").value, true);
   }
   else {
  xhttp.open("GET", "b_port_12?state_port_12="+ document.getElementById("port_12").value *(-1), true);
    } 
  xhttp.send();
}
</script>
</body>
</html>
)=====";
