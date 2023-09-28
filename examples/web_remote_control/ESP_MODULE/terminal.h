const char webpageTerminal[] PROGMEM = R"=====(
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

        .config_img {
            background-image: url("data:image/png;base64,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");
            background-size: cover;
            margin-left: 5px;
            margin-bottom: 2px;
            width: 59px;
            height: 50px;
            display: inline-block;
            vertical-align: bottom;
            float: left;
        }

        .wifi {
            background: #4cd8fb;
            padding: 1px;
            margin-bottom: 10px;
            width: 250px;
            border-radius: 30px;
            margin-left: 50px;
            border: 2px solid;
            display: inline-block;
        }

        .nanit_img {
            padding: 1px;
            margin-bottom: 10px;
            width: 250px;
            display: inline-block;
        }

        .wifi_set {
            background: yellow;
            padding: 1px;
            margin-bottom: 10px;
            width: auto;
            border-radius: 50px;
            text-align: center;
            border: 2px solid;
        }

        .buttonWifi_set {
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

        .buttonWifi {
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
            text-align: center;
        }

        .buttons_game {
            padding-top: 25px;
            font-size: 25px;
            padding-left: 100px;
        }

        .container_buttons {
            display: inline-block;

            align-items: center;

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
            margin-right: 100px;
            float: left;
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
            padding-left: 100px;
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

        .button_save {
            background: #fefb64;
            padding: 1px;
            margin-bottom: 10px;
            width: 100px;
            height: 50px;
            border-radius: 30px;
            font-size: 23px;
            font-weight: bold;
            border: 2px solid;
            margin-top: 10px;
        }

        .text_area {
            float: right;
            resize: none;
            width: 1300px;
            height: 600px;
            background-color: black;
            color: white;
        }

        .size_text {
            width: 900px;
            font-size: 23px;
            padding: 15px;
        }

        .center_text {
            float: right;
        }

        @media screen {
            @media (max-width: 1875px) {
                .wifi {
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
                    .wifi {
                        margin-left: 0px;
                    }

                    .text_area {
                        width: 800px;
                        height: 600px;
                    }

                    .size_text {
                        width: 600px;
                    }

                    @media (max-width: 1533px) {
                        .text_area {
                            width: 700px;
                            height: 600px;
                        }

                        .size_text {
                            width: 400px;
                        }

                        @media (max-width: 1255px) {
                            .text_area {
                                width: 600px;
                                height: 600px;
                            }

                            .size_text {
                                width: 400px;
                            }

                            @media (max-width: 1153px) {
                                .text_area {
                                    width: 500px;
                                    height: 600px;
                                }

                                .size_text {
                                    width: 300px;
                                }

                                @media (max-width: 1029px) {
                                    .text_area {
                                        width: 400px;
                                        height: 600px;
                                    }

                                    .size_text {
                                        width: 250px;
                                    }

                                    @media (max-width: 1029px) {
                                        .text_area {

                                            display: block;
                                            margin-left: auto;
                                            margin-right: auto;
                                            width: 370px;
                                            height: 600px;
                                        }

                                        .size_text {
                                            width: 250px;
                                        }

                                        @media (max-width: 920px) {
                                            .buttons_game {
                                                padding-left: 10px;
                                            }

                                            .text_area {
                                                float: left;
                                                display: block;
                                                margin-left: auto;
                                                margin-right: auto;
                                                width: 335px;
                                                height: 600px;
                                            }

                                            .size_text {
                                                width: 250px;
                                            }
                                        }
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

        <div class="wifi">
            <span class="home_img"></span><span><a href="/"><input type="button" name="" value="Home" class="buttonWifi"></a></span>
        </div>

        <div class="wifi">
            <span class="setting_img"></span><span><a href="/setting"><input type="button" name="" value="Setting" class="buttonWifi"></a></span>
        </div>

        <div class="wifi">
            <span class="controller_img"></span><span><a href="/gamePad"><input type="button" name="" value="Controller" class="buttonWifi"></a></span>
        </div>

        <div class="wifi">
            <span class="config_img"></span><span><a href="/config"><input type="button" name="" value="Config" class="buttonWifi"></a></span>
        </div>
    </center>



    <div class="wifi_set">
        <span><input type="button" name="" value="Terminal" class="buttonWifi_set"></span>
    </div>

    <div class="container1" style="padding-bottom: 10px;">
        <div class="container">
            <div class="port">PORT</div>
        </div>

        <div class="container">
            <div class="buttons_game">P1_Motor</div>
        </div>

        <div class="container">
            <div class="buttons_game">P2_Servo_motor</div>
        </div>

        <div class="container">
            <div class="buttons_game">P3_Motion_sensor</div>
        </div>

        <div class="container">
            <div class="buttons_game">P4_RGB</div>
        </div>

        <div class="container">
            <div class="buttons_game">P5_Sound_sensor</div>
        </div>

        <div class="container">
            <div class="buttons_game">P6_Ultrasonic_distance_sensor</div>
        </div>


        <div class="container">
            <div class="buttons_game">P7_Joystick</div>
        </div>

        <div class="container">
            <div class="buttons_game">P8_ESP</div>
        </div>


        <div class="container">
            <div class="buttons_game">P9_Gyroscope</div>
        </div>

        <div class="container">
            <div class="buttons_game">P10_Line_sensor</div>
        </div>

        <div class="container">
            <div class="buttons_game">P11_None</div>
        </div>

        <div class="container">
            <div class="buttons_game">P12_Motor</div>
        </div>



    </div>

    <div class="center_text">
        <div><textarea style="font-size: 30px; margin-bottom: 10px; border-radius: 30px; padding: 10px;" readonly class="text_area" id="output_text"></textarea></div>
        <div>
            <form method="get" action="/terminal_textBox" onsubmit="send_command(); return false;">
                    <input type="text" name="command_textBox" class="size_text" 
                    style="border: 1px solid; border-radius: 30px; height: 30px;" id="send_text_term"> 
                    <button class="button_save"  type="submit" >Submit</button>
                    <!--input type="submit"/>-->
            </form>
        </div>
    </div>

<script>
setInterval(function (){  
  output_text();
  }, 1000); // setting the delay time for output

function output_text() {
  var xhttp = new XMLHttpRequest();
  xhttp.onreadystatechange = function() {
    if (this.readyState == 4 && this.status == 200) {
      document.getElementById("output_text").innerHTML = this.responseText;
    }
  };
  xhttp.open("GET", "text_terminal", true);
  xhttp.send();
}
/*
State  Description
0      The request is not initialized
1      The request has been set up
2      The request has been sent
3      The request is in process
4      The request is complete
*/


function send_command() {
  
  if (document.getElementById("send_text_term").value !== "") {
    var xhttp_password = new XMLHttpRequest();
    
    xhttp_password.onreadystatechange = function() {
      if (this.readyState == 4 && this.status == 200) {
        document.getElementById("command_textBox").innerHTML = this.responseText;
      }
    };
    
    xhttp_password.open("GET", "terminal_textBox?command_textBox=" + document.getElementById("send_text_term").value, true);
    document.getElementById("send_text_term").value = "";
    xhttp_password.send();
    /* xhttp_password.cloce(); */
    
    isFunctionExecuted = true; // позначити, що функція була виконана
  }
}
</script>
</body>
</html>
)=====";
