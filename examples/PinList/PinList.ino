/////Library manual * ver 2.1 //////////////////////////////////////
//To access a pin in NANIT we use the following construction
//"P4_1" where P4 is the port, and _1 is the pin number in this port
//"P10_2" is analog only in Nanit version 3
//also "button" is a touch button on the front panel of Nanit (Attention! Use only as INPUT).
//
//When entering the name of the port and pin, it will have:
// black color - this means that this pin cannot be used;
// orange - this is a regular digital pin;
// orange bold - this is a digital pin that can generate a PWM signal
// blue - these are regular analog pins, they can also be used as digital
//
//Attention! pins P1_4 and P1_3 as well as P12_4 and P12_3 are outputs from the embedded driver and are intended for
//motors (voltage 3.7V)
//Attention! Power supply to ports 1, 2, 11, 12 - Has 3.7 (battery voltage).
//
//Functions:
//Touch button MODE --- BUTTON(); - returns true if the sensor interprets the pressing, otherwise false
//RGB module --- RGB(0,125,255); - specify the color
//The list of functions and pins on Nanit can be viewed in the table, in the NanitLib library folder
////////////////////////////////////////////////////////////////////

#include <NanitLib.h> ///Connect the library

void setup() {
 NanitStart(); //Initialize the library
	
pinMode(P4_3,OUTPUT); //We specify that on port 4, contact number 1 will be an output.
}

void loop() {
digitalWrite(P4_3,HIGH); //We apply a high signal level to 1 leg, 4 ports.
delay(500);
digitalWrite(P4_3,LOW); //We apply a low signal level to 1 leg, 4 ports.
delay(500);
}