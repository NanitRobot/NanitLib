#include <SoftwareSerial.h> // data transfer via UART
#include <NanitLib.h>

void setup() {
  Nanit_Base_Start();
  //MOTOR & BUTTON
  pinMode(40, OUTPUT);
  pinMode(3, INPUT);
  digitalWrite(40, 1);
  //PORT 1
  pinMode(P1_1, INPUT);
  pinMode(P1_2, INPUT);
  pinMode(P1_3, OUTPUT);
  pinMode(P1_4, OUTPUT);
  //PORT 2
  pinMode(P2_1, INPUT);
  pinMode(P2_2, INPUT);
  pinMode(P2_3, OUTPUT);
  pinMode(P2_4, INPUT);
  //PORT 3
  pinMode(P3_2, OUTPUT);
  pinMode(P3_3, OUTPUT);
  pinMode(P3_4, OUTPUT);
  //PORT 4
  pinMode(P4_1, INPUT);
  pinMode(P4_2, OUTPUT);
  pinMode(P4_3, OUTPUT);
  pinMode(P4_4, OUTPUT);
  //PORT 5
  pinMode(P5_1, OUTPUT);
  pinMode(P5_2, INPUT);
  pinMode(P5_3, INPUT);
  pinMode(P5_4, OUTPUT);
  //PORT 6
  pinMode(P6_1, OUTPUT);
  pinMode(P6_4, OUTPUT);
  //PORT 7
  pinMode(P7_1, INPUT);
  pinMode(P7_2, INPUT);
  pinMode(P7_3, OUTPUT);
  pinMode(P7_4, OUTPUT);
  //PORT 8
  pinMode(P8_3, OUTPUT);
  //PORT 9
  pinMode(P9_1, OUTPUT);
  pinMode(P9_2, OUTPUT);
  pinMode(P9_3, OUTPUT);
  pinMode(P9_4, OUTPUT);
  //PORT 10
  pinMode(P10_1, INPUT);
  pinMode(P10_2, INPUT);
  pinMode(P10_3, OUTPUT);
  pinMode(P10_4, OUTPUT);
  //PORT 11
  pinMode(P11_3, OUTPUT);
  pinMode(P11_4, OUTPUT);
  //PORT 12
  pinMode(P12_1, OUTPUT);
  pinMode(P12_2, OUTPUT);
  pinMode(P12_3, OUTPUT);
  pinMode(P12_4, OUTPUT);

  Serial.begin(9600);
  Serial3.begin(9600);
}
char   bufer_TX;
String byfer_UART;
String Comand;
// PORT STATUS
bool port1 = 0;
bool port2 = 0;
bool port3 = 0;
bool port4 = 0;
bool port5 = 0;
bool port6 = 0;
bool port7 = 0;
bool port8 = 0;
bool port9 = 0;
bool port10 = 0;
bool port11 = 0;
bool port12 = 0;

/*
  UR - Up Right motor
  UL - Up Left motor
  BR - Back Right
  BL - Back Left

  Port 1 - Right motor
  Port 12 - Left motor
*/
void motorRun(bool motorURState, bool motorBRState, bool motorULState, bool motorBLState) {
  // Right wheel //
  digitalWrite(P1_4, motorURState);
  digitalWrite(P1_3, motorBRState);
  // Left wheel //
  digitalWrite(P12_3, motorULState);
  digitalWrite(P12_4, motorBLState);
  delay(1000);
  digitalWrite(P1_3, 0);
  digitalWrite(P1_4, 0);
  digitalWrite(P12_3, 0);
  digitalWrite(P12_4, 0);
}

void Comand_Nanit(String value)
{
  /*            Joystick in site             */
  if (value == "_LYRIGHT") {
    Serial.println(value += "OK");
    motorRun(1, 0, 0, 0);
  }
  else if (value == "_LXDOWN") {
    Serial.println(value += "OK");
    motorRun(0, 1, 0, 1);
  }
  else if (value == "_LYLEFT") {
    Serial.println(value += "OK");
    motorRun(0, 0, 1, 0);
  }
  else if (value == "_LXUP") {
    Serial.println(value += "OK");
    motorRun(1, 0, 1, 0);
  }
  else if (value == "_RYRIGHT") {
    Serial.println(value += "OK");
  }
  else if (value == "_RXDOWN") {
    Serial.println(value += "OK");
  }
  else if (value == "_RYLEFT") {
    Serial.println(value += "OK");
  }
  else if (value == "_RXUP") {
    byfer_UART += "_IP? ";
    Serial.println(value += "OK");
  }
  else if (value == "_SERNOM?") {
    byfer_UART += "0x1S4DF0Q ";
    Serial.println(value += "OK");
  }
  //    READ ANALOG VALUES    //
  else if (value == "/p1_1read" && port1 == 1) {
    byfer_UART += String(analogRead(P1_1)) += " ";
    Serial.println(value += "OK");
  }
  else if (value == "/p1_2read" && port1 == 1) {
    byfer_UART += String(analogRead(P1_2)) += " ";
    Serial.println(value += "OK");
  }
  else if (value == "/p2_1read" && port2 == 1) {
    byfer_UART += String(analogRead(10)) += " ";
    Serial.println(value += "OK");
  }
  else if (value == "/p2_2read" && port2 == 1) {
    byfer_UART += String(analogRead(P2_2)) += " ";
    Serial.println(value += "OK");
  }
  else if (value == "/p2_4read" && port2 == 1) {
    byfer_UART += String(analogRead(P2_4)) += " ";
    Serial.println(value += "OK");
  }
  else if (value == "/p4_1read" && port4 == 1) {
    byfer_UART += String(analogRead(P4_1)) += " ";
    Serial.println(value += "OK");
  }
  else if (value == "/p5_2read" && port5 == 1) {
    byfer_UART += String(analogRead(P5_2)) += " ";
    Serial.println(value += "OK");
  }
  else if (value == "/p5_3read" && port5 == 1) {
    byfer_UART += String(analogRead(P5_3)) += " ";
    Serial.println(value += "OK");
  }
  else if (value == "/p7_1read" && port7 == 1) {
    byfer_UART += String(analogRead(P7_1)) += " ";
    Serial.println(value += "OK");
  }
  else if (value == "/p7_2read" && port7 == 1) {
    byfer_UART += String(analogRead(P7_2)) += " ";
    Serial.println(value += "OK");
  }
  else if (value == "/p10_1read" && port10 == 1) {
    byfer_UART += String(analogRead(P10_1)) += " ";
    Serial.println(value += "OK");
  }
  else if (value == "/p10_2read" && port10 == 1) {
    byfer_UART += String(analogRead(P10_2)) += " ";
    Serial.println(value += "OK");
  }
  /*            USER COMMANDS            */


  /*            PORTS status             */
  //PORT 1 - MOTOR
  if (value == "_PORT1CONNECT") {
    port1 = 1;
    Serial.println(port1);
  }
  else if (value == "_PORT1DISCONNECT") {
    port1 = 0;
    Serial.println(port1);
  }

  if (port1 == 1 && value == "/p1_3on") {
    digitalWrite(P1_3, 1);
    digitalWrite(P1_4, 0);
  }
  else if (port1 == 1 && value == "/p1_3off") {
    digitalWrite(P1_3, 0);
    digitalWrite(P1_4, 0);
  }

  else if (port1 == 0) {
    digitalWrite(P1_3, 0);
    digitalWrite(P1_4, 0);
  }
  //PORT 2 - SERVO MOTOR
  if (value == "_PORT2CONNECT") {
    port2 = 1;
    Serial.println(port2);
  }
  else if (value == "_PORT2DISCONNECT") {
    port2 = 0;
    Serial.println(port2);
  }

  //PORT 3 - MOTION SENSOR
  if (value == "_PORT3CONNECT") {
    port3 = 1;
    Serial.println(port3);
  }
  else if (value == "_PORT3DISCONNECT") {
    port3 = 0;
    Serial.println(port3);
  }

  else if (port3 == 1 && value == "/p3_2on") {
    digitalWrite(P3_2, 1);
  }
  else if (port3 == 1 && value == "/p3_2off") {
    digitalWrite(P3_2, 0);
  }
  else if (port3 == 1 && value == "/p3_3on") {
    digitalWrite(P3_3, 1);
  }
  else if (port3 == 1 && value == "/p3_3off") {
    digitalWrite(P3_3, 0);
  }
  else if (port3 == 1 && value == "/p3_4on") {
    digitalWrite(P3_4, 1);
  }
  else if (port3 == 1 && value == "/p3_4off") {
    digitalWrite(P3_4, 0);
  }

else if (port3 == 0) {
    digitalWrite(P3_2, 0);
    digitalWrite(P3_3, 0);
    digitalWrite(P3_4, 0);
  }

  //PORT 4 - RGB
  if (value == "_PORT4CONNECT") {
    port4 = 1;
    Serial.println(port4);
  }
  else if (value == "_PORT4DISCONNECT") {
    port4 = 0;
    Serial.println(port4);
  }

  if (port4 == 1 && value == "/p4_2on") {
    digitalWrite(P4_2, 1);
  }
  else if (port4 == 1 && value == "/p4_2off") {
    digitalWrite(P4_2, 0);
  }
  else if (port4 == 1 && value == "/p4_3on") {
    digitalWrite(P4_3, 1);
  }
  else if (port4 == 1 && value == "/p4_3off") {
    digitalWrite(P4_3, 0);
  }
  else if (port4 == 1 && value == "/p4_4on") {
    digitalWrite(P4_4, 1);
  }
  else if (port4 == 1 && value == "/p4_4off") {
    digitalWrite(P4_4, 0);
  }
  else if (port4 == 0) {
    digitalWrite(P4_2, 0);
    digitalWrite(P4_3, 0);
    digitalWrite(P4_4, 0);
  }

  //PORT 5 - SOUND SENSOR
  if (value == "_PORT5CONNECT") {
    port5 = 1;
    Serial.println(port5);
  }
  else if (value == "_PORT5DISCONNECT") {
    port5 = 0;
    Serial.println(port5);
  }

  if (port5 == 1 && value == "/p5_1on") {
    digitalWrite(P5_1, 1);
  }
  else if (port5 == 1 && value == "/p5_1off") {
    digitalWrite(P5_1, 0);
  }
  else if (port5 == 1 && value == "/p5_4on") {
    digitalWrite(P5_4, 1);
  }
  else if (port5 == 1 && value == "/p5_4off") {
    digitalWrite(P5_4, 0);
  }

  else if (port5 == 0) {
    digitalWrite(P5_1, 0);
    digitalWrite(P5_4, 0);
  }
  //PORT 6 - ULTRASONIC /ESP
  if (value == "_PORT6CONNECT") {
    port6 = 1;
    Serial.println(port6);
  }
  else if (value == "_PORT6DISCONNECT") {
    port6 = 0;
    Serial.println(port6);
  }

  if (port6 == 1 && value == "/p6_1on") {
    digitalWrite(P6_1, 0);
  }
  else if (port6 == 1 && value == "/p6_1off") {
    digitalWrite(P6_1, 0);
  }
  else if (port6 == 1 && value == "/p6_4on") {
    digitalWrite(P6_4, 1);
  }
  else if (port6 == 1 && value == "/p6_4off") {
    digitalWrite(P6_4, 0);
  }
  //PORT 7 - JOYSTICK
  if (value == "_PORT7CONNECT") {
    port7 = 1;
    Serial.println(port7);
  }
  else if (value == "_PORT7DISCONNECT") {
    port7 = 0;
    Serial.println(port7);
  }

  if (port7 == 1 && value == "/p7_3on") {
    digitalWrite(P7_3, 1);
  }
  else if (port7 == 1 && value == "/p7_3off") {
    digitalWrite(P7_3, 0);
  }
  else if (port7 == 1 && value == "/p7_4on") {
    digitalWrite(P7_4, 1);
  }
  else if (port7 == 1 && value == "/p7_4off") {
    digitalWrite(P7_4, 0);
  }
  //PORT 8 - NONE
  if (value == "_PORT8CONNECT") {
    port8 = 1;
    Serial.println(port8);
  }
  else if (value == "_PORT8DISCONNECT") {
    port8 = 0;
    Serial.println(port8);
  }

  if (port8 == 1 && value == "/p8_3on") {
    digitalWrite(P8_3, 1);
  }
  else if (port8 == 1 && value == "/p8_3off") {
    digitalWrite(P8_3, 0);
  }
  //PORT 9 - GYROSCOPE
  if (value == "_PORT9CONNECT") {
    port9 = 1;
    Serial.println(port9);
  }
  else if (value == "_PORT9DISCONNECT") {
    port9 = 0;
    Serial.println(port9);
  }

  if (port9 == 1 && value == "/p9_1on") {
    digitalWrite(P9_1, 1);
  }
  else if (port9 == 1 && value == "/p9_1off") {
    digitalWrite(P9_1, 0);
  }
  else if (port9 == 1 && value == "/p9_2on") {
    digitalWrite(P9_2, 1);
  }
  else if (port9 == 1 && value == "/p9_2off") {
    digitalWrite(P9_2, 0);
  }
  else if (port9 == 1 && value == "/p9_3on") {
    digitalWrite(P9_3, 1);
  }
  else if (port9 == 1 && value == "/p9_3off") {
    digitalWrite(P9_3, 0);
  }
  else if (port9 == 1 && value == "/p9_4on") {
    digitalWrite(P9_4, 1);
  }
  else if (port9 == 1 && value == "/p9_4off") {
    digitalWrite(P9_4, 0);
  }
  //PORT 10 - LIGHT SENSOR
  if (value == "_PORT10CONNECT") {
    port10 = 1;
    Serial.println(port10);
  }
  else if (value == "_PORT10DISCONNECT") {
    port10 = 0;
    Serial.println(port10);
  }

if (port10 == 1 && value == "/p10_3on") {
    digitalWrite(P10_3, 1);
  }
  else if (port10 == 1 && value == "/p10_3off") {
    digitalWrite(P10_3, 0);
  }
  else if (port10 == 1 && value == "/p10_4on") {
    digitalWrite(P10_4, 1);
  }
  else if (port10 == 1 && value == "/p10_4off") {
    digitalWrite(P10_4, 0);
  }
  //PORT 11 - NONE
  if (value == "_PORT11CONNECT") {
    port11 = 1;
    Serial.println(port11);
  }
  else if (value == "_PORT11DISCONNECT") {
    port11 = 0;
    Serial.println(port11);
  }

  if (port11 == 1 && value == "/p11_3on") {
    digitalWrite(P11_3, 1);
  }
  else if (port11 == 1 && value == "/p11_3off") {
    digitalWrite(P11_3, 0);
  }
  else if (port11 == 1 && value == "/p11_4on") {
    digitalWrite(P11_4, 1);
  }
  else if (port11 == 1 && value == "/p11_4off") {
    digitalWrite(P11_4, 0);
  }
  //PORT 12 - MOTOR
  if (value == "_PORT12CONNECT") {
    port12 = 1;
    Serial.println(port12);
  }
  else if (value == "_PORT12DISCONNECT") {
    port12 = 0;
    Serial.println(port12);
  }

  if (port12 == 1 && value == "/p12_1on") {
    digitalWrite(P12_1, 1);
  }
  else if (port12 == 1 && value == "/p12_1off") {
    digitalWrite(P12_1, 0);
  }
  else if (port12 == 1 && value == "/p12_2on") {
    digitalWrite(P12_2, 1);
  }
  else if (port12 == 1 && value == "/p12_2off") {
    digitalWrite(P12_2, 0);
  }
  else if (port12 == 1 && value == "/p12_3on") {
    digitalWrite(P12_3, 1);
  }
  else if (port12 == 1 && value == "/p12_3off") {
    digitalWrite(P12_3, 0);
  }
  else if (port12 == 1 && value == "/p12_4on") {
    digitalWrite(P12_4, 1);
  }
  else if (port12 == 1 && value == "/p12_4off") {
    digitalWrite(P12_4, 0);
  }

  else if (port12 == 0) {
    digitalWrite(12, 0);
    digitalWrite(11, 0);
  }

  else {
    Serial.println(value);
  }
}

void loop() {
  if (Serial3.available()) //if data is coming
  {
    bufer_TX = Serial3.read();
    if (bufer_TX == ' ')
    {
      Comand_Nanit(Comand);
      Comand.remove(0);
    }
    else
    {
      Comand += bufer_TX;
    }
  }

  if (byfer_UART != "") //if there is a need to send data
  {
    Serial3.print(byfer_UART);
    byfer_UART.remove(0);
  }
}
