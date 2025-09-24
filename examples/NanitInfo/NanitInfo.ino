/************************************************************************
| * @file NanitInfo.ino
| * @author Sam4uk
| * @date 04-04-2023
| *
| * Instructions
| * ==========
| *
| * To start using the library, you need to include the header file
| */

#include <NanitLib.h>

/** After connecting this file, you have access to input/output ports
| * 12 ports are available for programming, each port has 4 pins
| * for input/output and two pins for powering an external sensor
| * (+) and (-) power.
| * (-) is common to all ports
| * (+) positive power pole. Ports 1, 2, 11 and 12 are powered directly
| * from the built-in rechargeable battery. Depending on the state of charge of the battery, the voltage can be between 4.2 (full charge) and 2.7
| * (full discharge) volts. Other ports have a stabilized supply voltage
| * 5 volts.
| *
| * Pin reference
| *    P3_1
| *    ^^ ^
| *    || |
| *    || +--- Pin number (number from 1 to 4)
| *    |+----- Port number (number from 1 to 12)
| *    +------ Required port pin attribute
| *
\******************************************************************************/
void setup() {
/// Function that displays the message "Hello Nanit" on the built-in display
/// Hardware version
/// Library version
/// Battery level
  Serial.begin(NANIT_SERIAL_SPEED);
  NanitInfo();
}
void loop() {
/// Nanit does not perform any useful work
}