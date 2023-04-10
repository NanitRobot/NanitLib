#!/bin/bash
git submodule add https://github.com/MCUdude/MegaCore
git submodule update --init --recursive
#make filepath


NANIT_PATH="./Nanit"
MEGACORE_PATH="./MegaCore"

NANIT_LIBRARY_PATH="${NANIT_PATH}/libraries"
MEGACORE_LIBRARY_PATH="${MEGACORE_PATH}/avr/libraries"

NANIT_CORE_PATH="${NANIT_PATH}/cores/"
MEGACORE_CORE_PATH="${MEGACORE_PATH}/avr/cores/MCUdude_corefiles"

PINS_PATH="./Nanit/variants/Nanit"
PINS_ARDUINO="pins_arduino.h"
#pins
mkdir -p ${PINS_PATH}
cp -ruf ./MegaCore/avr/variants/100-pin-arduino-mega/pins_arduino.h ${PINS_PATH}/${PINS_ARDUINO}
#liblaries
mkdir -p ${NANIT_LIBRARY_PATH}
# HID
# SPI
# SoftwareSerial
# Wire
cp -ruf ${MEGACORE_LIBRARY_PATH}/EEPROM/ ${NANIT_LIBRARY_PATH}/EEPROM/
cp -ruf ${MEGACORE_LIBRARY_PATH}/HID/ ${NANIT_LIBRARY_PATH}/HID/
cp -ruf ${MEGACORE_LIBRARY_PATH}/SPI/ ${NANIT_LIBRARY_PATH}/SPI/
cp -ruf ${MEGACORE_LIBRARY_PATH}/SoftwareSerial/ ${NANIT_LIBRARY_PATH}/SoftwareSerial/
cp -ruf ${MEGACORE_LIBRARY_PATH}/Wire/ ${NANIT_LIBRARY_PATH}/Wire/
#core
mkdir -p ${NANIT_CORE_PATH}
cp -ruf ${MEGACORE_CORE_PATH}/ ${NANIT_CORE_PATH}/

# КОСТИЛЬ
mv ${NANIT_CORE_PATH}/MCUdude_corefiles "${NANIT_CORE_PATH}/MegaCore"

unzip -o NanitIDE.zip -d ${NANIT_PATH}

zip -qq -r NanitCore.zip ${NANIT_PATH}
rm -fr ${NANIT_PATH}

git submodule deinit -f MegaCore

rm -fr ${MEGACORE_PATH}