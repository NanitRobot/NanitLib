// ----------------------------------------------
#include <EEPROM.h> //library for working with EEPROM
// ----------------------------------------------
#include <ESP8266WiFi.h> //library for Wi-Fi support on ESP8266
#include <ESP8266WebServer.h> //library for creating a web server
// ----------------------------------------------
#include <DNSServer.h> //library for DNS server
#include <ESP8266LLMNR.h> //library for accessing an HTML page through the domain http://nanit/
#include <ESP8266mDNS.h> //library for accessing an HTML page through the domain http://nanit.local/
// ----------------------------------------------
#include <WiFiUdp.h> //ESP8266 UDP communication
#include <ArduinoOTA.h> //Library for OTA firmware
// ----------------------------------------------
#include <SoftwareSerial.h> //data transfer via UART
// ----------------------------------------------

#include "esp_buildin.h"
char bufer_TX;
char bufer_RX;
String Comand;

String byfer_UART;
String ssid;
String password;

int addr_ssid = 0;  //the starting address to write the SSID into the EEPROM
int addr_password = 5;  //the starting address to write PASSWORD in EEPROM

const byte DNS_PORT = 53; //port for DNS

String terminal;

int task_to_transfer = 0; //send task check box
IPAddress apIP(192, 168, 1, 1);
DNSServer dnsServer;
ESP8266WebServer server(80); //

String serialNumber = "0x0000000";

#include "index.h"                //connecting HTML pages
#include "setting.h"
#include "gamepad.h"
#include "gamepad_simple.h"
#include "terminal.h"
#include "config.h"

#include "setting_gamepad.h" 
#include "config_connect.h"

int i;
void HomePage()
{
  BLUE_ON();
  server.send(200, "text/html", webpageHome);   //Main page
  BLUE_OFF();
}

void SettingPage()
{
    BLUE_ON();
  server.send(200, "text/html", webpageSetting);   //settings page
  BLUE_OFF();
}

void GamePadPage()
{
    BLUE_ON();
  server.send(200, "text/html", webpageGamePad);   //joystick page
  BLUE_OFF();
}

void GamePadSimple()
{
    BLUE_ON();
  server.send(200, "text/html", webpageGamePadSimple);   //simple joystick page
  BLUE_OFF();
}

void TerminalPage()
{
    BLUE_ON();
  server.send(200, "text/html", webpageTerminal);   //terminal page
  BLUE_OFF();
}

void ConfigPage()
{
    BLUE_ON();
  server.send(200, "text/html", webpageConfig);   //peripheral connection page
  BLUE_OFF();
}


void  outPage_serial () {              //output of the serial number to the /setting page
  BLUE_ON();
  String serial = serialNumber;
  server.send(200, "text/plane", serial); //send the page to the server
  BLUE_OFF();
}

void  outPage_ip () {              //ip output to the /setting page
  BLUE_ON();
  String ip = WiFi.localIP().toString();
  server.send(200, "text/plane", ip); //send the page to the server
  BLUE_OFF();
}

void  outPage_wifi () {              //Wi-Fi hotspot output on the /setting page
  BLUE_ON();
  String wifi = String("Nanit_" + serialNumber);
  server.send(200, "text/plane", wifi); //send the page to the server
  BLUE_OFF();
}

void  outPage_ssid () {              //displaying the SSID on the /setting page
  BLUE_ON();
  String ss = String(ssid);
  server.send(200, "text/plane", ss); //send the page to the server
  BLUE_OFF();
}

void  outPage_password () {              //output PASSWORD to the /setting page
  BLUE_ON();
  String pass = String(password);
  server.send(200, "text/plane", pass); //send the page to the server
  BLUE_OFF();
}

void outPage_terminal () {
    BLUE_ON();
  server.send(200, "text/plane", terminal); //send the page to the server
  BLUE_OFF();
}

void term_text() {
    BLUE_ON();
  // outputting text from the TextBox of the /terminal page !!!!!!!!!!!!!!!!!!
  if (server.arg("command_textBox") != "") {
    byfer_UART += server.arg("command_textBox");
    byfer_UART += " ";
  }
  server.send(200, "text/plane", terminal);
  BLUE_OFF();
}

void button_left() {                               //joystick buttons on the left
  if (server.arg("state_l") == "1") byfer_UART += "_LYRIGHT "; //_LYRIGHT
  else if (server.arg("state_l") == "2") byfer_UART += "_LXDOWN "; //_LXDOWN
  else if (server.arg("state_l") == "3") byfer_UART += "_LYLEFT "; //_LYLEFT
  else if (server.arg("state_l") == "4") byfer_UART += "_LXUP "; //_LXUP
}

void button_right() {                              //joystick buttons on the right
  if (server.arg("state_r") == "1")byfer_UART += "_RYRIGHT "; //_RYRIGHT
  else if (server.arg("state_r") == "2")byfer_UART += "_RXDOWN ";//_RXDOWN
  else if (server.arg("state_r") == "3")byfer_UART += "_RYLEFT ";//_RYLEFT
  else if (server.arg("state_r") == "4")byfer_UART += "_RXUP "; //_RXUP
}
int xValue = 0;
int yValue = 0;
bool openButtonState = false;
int sliderValue = 150;
int bValue = 0;

void handleJoystick() {
  BLUE_ON();
  xValue = server.arg("x").toInt();
  yValue = server.arg("y").toInt();
  Serial.print(xValue);
  Serial.print(",");
  Serial.print(yValue);
  Serial.print(",");
  Serial.print(sliderValue);
  Serial.print(",");
  Serial.println(bValue);
  server.send(200, "text/plain", "OK");
  BLUE_OFF();
}


void handleButton() {
    BLUE_ON();
  bValue = server.arg("value").toInt();
  /*Serial.print(xValue);
  Serial.print(",");
  Serial.print(yValue);
  Serial.print(",");
  Serial.print(sliderValue);
  Serial.print(",");

  Serial.print(bValue);
  Serial.println(' ');*/
  server.send(200, "text/plain", "OK");
  BLUE_OFF();
}

void handleSlider() {
    BLUE_ON();
  sliderValue = server.arg("value").toInt();
  /* Serial.print(xValue);
  Serial.print(",");
  Serial.print(yValue);
  Serial.print(",");
  Serial.print(sliderValue);
  Serial.print(",");
  Serial.println(openButtonState);*/
  server.send(200, "text/plain", "OK");
  BLUE_OFF();
}

void re_name_ssid() {                         //ssid change
  if (server.arg("rename_ssid") != "") {

    for (int i = 0; i < 31 ; i++)
    {
      if (i < server.arg("rename_ssid").length() ) {
        EEPROM.write(0x00 + i, server.arg("rename_ssid")[i]);
      }
      else {
        EEPROM.write(0x00 + i, '`');
      }
    }
    EEPROM.commit();
  }
  else if (server.arg("rename_ssid") == "") Serial.println("Not select_ssid");
}
void re_name_password() {           //password change
  if (server.arg("rename_password") != "") {
    for (int i = 0; i < 31 ; i++)
    {
      if (i < server.arg("rename_password").length() ) {
        EEPROM.write(0x1F + i, server.arg("rename_password")[i]);
      }
      else {
        EEPROM.write(0x1F + i, '`');
      }
    }
    EEPROM.commit();
  }
  else if (server.arg("rename_password") == "")Serial.println("Not select_password");
}
constexpr uint8_t PushButton= 4;
void setup(void)
{
  RED_ON();
  EEPROM.begin(512); //initialization and allocation of memory from EEPROM
  Serial.begin(57600); //Data transfer speed

  byfer_UART.remove(0);
  byfer_UART += " _SERNOM?  ";
  delay(100);
  if (serialNumber == "0x0000000") {
    Serial.print(byfer_UART);
    terminal += "<<OUTPUT<<:";
    terminal += byfer_UART;
    terminal += "\n";
    delay(100);
    byfer_UART.remove(0);
  }

  pinMode(PushButton,INPUT_PULLUP);
  while (1)
  {
    if(millis()>30000 or ! digitalRead(PushButton)){
      serialNumber="XXXXXXXXXX";
      break;
    }
    if (Serial.available()) //if data is coming
    {
      bufer_TX = Serial.read();
      if (bufer_TX == ' ')
      {
        Serial.print(Comand);
        serialNumber = Comand;
        terminal += ">>INPUT>>:";
        terminal += Comand;
        terminal += "\n";
        Comand.remove(0);
        break;
      }
      else
      {
        Comand += bufer_TX;
      }
    }
  }

  for (int i = 0; i < 32; i++)
  {
    if (char(EEPROM.read(0x00 + i)) != '`') {
      ssid = ssid + char(EEPROM.read(0x00 + i));
    }
    else {
      break;
    }
  }

  for (int i = 0; i < 32; i++)
  {
    if (char(EEPROM.read(0x1F + i)) != '`') {
      password = password + char(EEPROM.read(0x1F + i));
    }
    else {
      break;
    }
  }

  WiFi.begin(ssid, password); //connecting to an access point


  for (i = 0; i <= 5; i++)
  {
    delay(3000);
    if (WiFi.status() == WL_CONNECTED) break;
    else if (i == 5 && WiFi.status() != WL_CONNECTED) {
      WiFi.disconnect();
      WiFi.mode(WIFI_AP);
      WiFi.softAPConfig(apIP, apIP, IPAddress(255, 255, 255, 0));
      WiFi.softAP("Nanit_" + serialNumber);
      break;
    }
    delay(500);
  }

  RED_OFF();

  if (serialNumber == 0x0000000) {
    while (serialNumber != 0x0000000) {
      if (Serial.available()) //if data is coming
      {
        serialNumber = Serial.read();
      }
      else
      {
        Serial.write("_SERNOM$?");
      }
    }
  }

  const char *byf = serialNumber.c_str();

  ArduinoOTA.setHostname(byf); //The name of the device in the network
  ArduinoOTA.setPassword((const char *)"0000"); //Access password for remote firmware
  ArduinoOTA.begin(); //OTA initialization


  outPage_ip(); //function to get ip
  outPage_wifi(); //function to get ssid for wifi hotspot

  dnsServer.start(DNS_PORT, "*", apIP);
  server.onNotFound([]() {
    HomePage();
  });
  server.on("/", HomePage); //start page
  server.on("/setting", SettingPage); //peripheral setup page
  server.on("/gamePad", GamePadPage); //joystick page
  server.on("/gamePadSimple", GamePadSimple); //simple joystick page
  server.on("/terminal", TerminalPage); //terminal page
  server.on("/config", ConfigPage); //peripheral connection page

/*****************************************************************/
  server.on("/joystick", handleJoystick);
  server.on("/button", handleButton);  // Обробник для кнопок
  server.on("/slider", handleSlider);  // Обробник для слайдера
/*****************************************************************/

  server.on("/b_left", button_left); //control with the left joystick buttons
  server.on("/b_right", button_right); //control with the right joystick buttons

  server.on("/textPage_serial", outPage_serial); //output of the serial number to the /setting page
  server.on("/textPage_ip", outPage_ip); //IP address output on the /setting page
  server.on("/textPage_wifi", outPage_wifi); //Wi-Fi output on the /setting page
  server.on("/textPage_ssid", outPage_ssid); //ssid output to the /setting page
  server.on("/textPage_password", outPage_password); //password output to the /setting page


  /*Termianl*/
  server.on("/text_terminal", outPage_terminal); //text output to the /terminal page
  server.on("/terminal_textBox", term_text); //Output of text from the text field of the /terminal page

  server.on("/b_right_y", right_y); //RIGHT BUTTON Y
  server.on("/b_right_x", right_x); //RIGHT BUTTON X
  server.on("/b_left_y", left_y); //LEFT BUTTON Y
  server.on("/b_left_x", left_x); //LEFT BUTTON X

  server.on("/b_port_1", port_1); //port 1   page /config
  server.on("/b_port_2", port_2); //port 2
  server.on("/b_port_3", port_3); //port 3
  server.on("/b_port_4", port_4); //port 4
  server.on("/b_port_5", port_5); //port 5
  server.on("/b_port_6", port_6); //port 6
  server.on("/b_port_7", port_7); //port 7
  server.on("/b_port_8", port_8); //port 8
  server.on("/b_port_9", port_9); //port 9
  server.on("/b_port_10", port_10); //port 10
  server.on("/b_port_11", port_11); //port 11
  server.on("/b_port_12", port_12); //port 12

  server.on("/ssid", re_name_ssid); //ssid
  server.on("/password", re_name_password); //password


  server.begin(); //Initialization of pages

  LLMNR.begin("nanit"); //domain http://nanit/

  MDNS.addService("http", "tcp", 80);
  MDNS.begin("nanit");    //domain http://nanit.local/
}

void Comand_Nanit(String value) {
  if (value == "_IP?")
  {
    byfer_UART += WiFi.localIP().toString();
    byfer_UART += " ";
    Serial.println("IP YES");
  }
}

void Nanit_UART()
{
  if (Serial.available()) //if data is coming
  {
    bufer_TX = Serial.read();
    if (bufer_TX == ' ')
    {
      Comand_Nanit(Comand);
      terminal += ">>INPUT>>:";
      terminal += Comand;
      terminal += "\n";
      Comand.remove(0);
    }
    else
    {
      Comand += bufer_TX;
    }
  }
  if (byfer_UART != "") //send data
  {
    Serial.print(byfer_UART);
    if (terminal.length() > 1000) {
      terminal.remove(0);
    }
    terminal += "<<OUTPUT<<:";
    terminal += byfer_UART;
    terminal += "\n";
    byfer_UART.remove(0);
  }
}

void loop(void)
{
  ArduinoOTA.handle(); //Always ready to stitch
  Nanit_UART(); //command handler
  dnsServer.processNextRequest();
  server.handleClient();
  MDNS.update();
}
