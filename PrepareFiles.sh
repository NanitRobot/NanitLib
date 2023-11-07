#!/bin/bash
# Базові налаштування
NANIT_PATH="./Nanit"
MEGACORE_PATH="./MegaCore"
# Додаємо репозиторії які розбиремо на донорські файли
# Megacore треба зробити форк
git submodule add https://github.com/MCUdude/MegaCore
git submodule add https://github.com/adafruit/Adafruit-GFX-Library
git submodule update --init --recursive
# Обраховуємо додадкові шляхи

NANIT_LIBRARY_PATH="${NANIT_PATH}/libraries"
MEGACORE_LIBRARY_PATH="${MEGACORE_PATH}/avr/libraries"

NANIT_CORE_PATH="${NANIT_PATH}/cores/"
MEGACORE_CORE_PATH="${MEGACORE_PATH}/avr/cores/MCUdude_corefiles"

PINS_PATH="./Nanit/variants/Nanit"
PINS_ARDUINO="pins_arduino.h"
# Створюємо шлях для заголовчного файлц визначення пінів
mkdir -p ${PINS_PATH}
#git submodule add https://github.com/NanitRobot/hex "${NANIT_PATH}/bootloaders"
cp cp binary/*.hex "${NANIT_PATH}/bootloaders/"
# Копіюємо файл
cp -ruf ./MegaCore/avr/variants/100-pin-arduino-mega/pins_arduino.h ${PINS_PATH}/${PINS_ARDUINO}
# Бібліотеки 
# TODO зробити красиво в циклі
mkdir -p ${NANIT_LIBRARY_PATH}

touch "${NANIT_LIBRARY_PATH}/touch"

cp -ruf ${MEGACORE_LIBRARY_PATH}/EEPROM/ ${NANIT_LIBRARY_PATH}/EEPROM/
# HID
cp -ruf ${MEGACORE_LIBRARY_PATH}/HID/ ${NANIT_LIBRARY_PATH}/HID/
# SPI
cp -ruf ${MEGACORE_LIBRARY_PATH}/SPI/ ${NANIT_LIBRARY_PATH}/SPI/
# SoftwareSerial
cp -ruf ${MEGACORE_LIBRARY_PATH}/SoftwareSerial/ ${NANIT_LIBRARY_PATH}/SoftwareSerial/
# Wire
cp -ruf ${MEGACORE_LIBRARY_PATH}/Wire/ ${NANIT_LIBRARY_PATH}/Wire/
# Шрифти
cp -ruf ./Adafruit-GFX-Library/Fonts/ ${NANIT_LIBRARY_PATH}/Fonts/
#core
mkdir -p ${NANIT_CORE_PATH}
cp -ruf ${MEGACORE_CORE_PATH}/ ${NANIT_CORE_PATH}/

# КОСТИЛЬ
mv ${NANIT_CORE_PATH}/MCUdude_corefiles "${NANIT_CORE_PATH}/MegaCore"

#rm -fr "${NANIT_PATH}/bootloaders/.git*"
# Розпаковуємо підготовлені файли
unzip -o NanitIDE.zip -d ${NANIT_PATH}
# Пакуємо файл 
zip -qq -r NanitCore.zip ${NANIT_PATH}

# Прибираємо за собою
rm -fr ${NANIT_PATH}

git submodule deinit -f MegaCore Adafruit-GFX-Library # Nanit/bootloaders
git rm -fr ${MEGACORE_PATH}
git rm -fr ./Adafruit-GFX-Library