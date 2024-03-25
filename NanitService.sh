#!/bin/bash
#файл генерує json файл параметри запуску
# https://arduino.github.io/arduino-cli/0.32/package_index_json-specification/

#sh ./MakePackageJson.sh  {{GITHUB_REPOSITORY}} $(sha256sum NanitCore.zip)

EMAIL="sales@nanitrobot.com"
HELP_ONLINE="https://nanitrobot.com/"

GITHUB_OWNER_REPO=${1}
SHA256=${2}
FILE_NAME=${3}
SHA256_2=${4}
FILE_NAME_2=${5}
OUT_FILE="package_NanitService_index.json"
FILE_SIZE=$(stat -c %s ${FILE_NAME})
OWNER=$(echo "${GITHUB_OWNER_REPO}" | cut -d '/' -f 1)
REPO=$(echo "${GITHUB_OWNER_REPO}" | cut -d '/' -f 2)

HOST="https://${OWNER}.github.io"
FILE_PATH="${REPO}/"

DOWNLOAD_URL="${HOST}/${REPO}/${FILE_NAME}"
WEB_SITE_URL="${HOST}/${REPO}"
# mails=$(echo $IN | tr "/" "\n")
echo "FIRST${0}"
echo "GITHUB_OWNER_REPO ${GITHUB_OWNER_REPO}"
echo "OWNER ${OWNER}"
echo "REPO ${REPO}"
echo "DOWNLOAD_URL ${DOWNLOAD_URL}"
echo "FILE_SIZE ${FILE_SIZE}"

cat <<EOF > "${OUT_FILE}"
{
  "packages": [
    {
      "name": "NanitService",
      "maintainer": "NanitRobots(NanitService)",
      "websiteURL": "${WEB_SITE_URL}",
      "email": "${EMAIL}",
      "help": {
        "online": "${HELP_ONLINE}"
      },
      "platforms": [
                {
          "name": "NanitService(NanitService)",
          "architecture": "avr",
          "version": "$(date +%-y.%-m.%-d)",
          "category": "Contributed",
          "help": {
            "online": "${HELP_ONLINE}"
          },
          "url": "${HOST}/${FILE_PATH}${FILE_NAME}",
          "archiveFileName": "${FILE_NAME}",
          "checksum" : "SHA-256:${SHA256}",
          "size" : "${FILE_SIZE}",
          "boards": [
            {
              "name": "SERVICE NANIT BARDS"
            }
          ]
        }
      ]
    }
  ],
  "toolsDependencies": [
            {
              "packager": "arduino",
              "name": "avr-gcc",
              "version": "7.3.0-atmel3.6.1-arduino7"
            },
            {
              "packager": "MegaCore",
              "name": "avrdude",
              "version": "7.2-arduino.1"
            },
            {
              "packager": "arduino",
              "name": "arduinoOTA",
              "version": "1.3.0"
            }
          ],
          "tools": [
        {
          "name": "avr-gcc",
          "version": "7.3.0-atmel3.6.1-arduino7",
          "systems": [
            {
              "size": "34683056",
              "checksum": "SHA-256:3903553d035da59e33cff9941b857c3cb379cb0638105dfdf69c97f0acc8e7b5",
              "host": "arm-linux-gnueabihf",
              "archiveFileName": "avr-gcc-7.3.0-atmel3.6.1-arduino7-arm-linux-gnueabihf.tar.bz2",
              "url": "http://downloads.arduino.cc/tools/avr-gcc-7.3.0-atmel3.6.1-arduino7-arm-linux-gnueabihf.tar.bz2"
            },
            {
              "size": "38045723",
              "checksum": "SHA-256:03d322b9df6da17289e9e7c6233c34a8535d9c645c19efc772ba19e56914f339",
              "host": "aarch64-linux-gnu",
              "archiveFileName": "avr-gcc-7.3.0-atmel3.6.1-arduino7-aarch64-pc-linux-gnu.tar.bz2",
              "url": "http://downloads.arduino.cc/tools/avr-gcc-7.3.0-atmel3.6.1-arduino7-aarch64-pc-linux-gnu.tar.bz2"
            },
            {
              "size": "36684546",
              "checksum": "SHA-256:f6ed2346953fcf88df223469088633eb86de997fa27ece117fd1ef170d69c1f8",
              "host": "x86_64-apple-darwin14",
              "archiveFileName": "avr-gcc-7.3.0-atmel3.6.1-arduino7-x86_64-apple-darwin14.tar.bz2",
              "url": "http://downloads.arduino.cc/tools/avr-gcc-7.3.0-atmel3.6.1-arduino7-x86_64-apple-darwin14.tar.bz2"
            },
            {
              "size": "52519412",
              "checksum": "SHA-256:a54f64755fff4cb792a1495e5defdd789902a2a3503982e81b898299cf39800e",
              "host": "i686-mingw32",
              "archiveFileName": "avr-gcc-7.3.0-atmel3.6.1-arduino7-i686-w64-mingw32.zip",
              "url": "http://downloads.arduino.cc/tools/avr-gcc-7.3.0-atmel3.6.1-arduino7-i686-w64-mingw32.zip"
            },
            {
              "size": "37176991",
              "checksum": "SHA-256:954bbffb33545bcdcd473af993da2980bf32e8461ff55a18e0eebc7b2ef69a4c",
              "host": "i686-linux-gnu",
              "archiveFileName": "avr-gcc-7.3.0-atmel3.6.1-arduino7-i686-pc-linux-gnu.tar.bz2",
              "url": "http://downloads.arduino.cc/tools/avr-gcc-7.3.0-atmel3.6.1-arduino7-i686-pc-linux-gnu.tar.bz2"
            },
            {
              "size": "37630618",
              "checksum": "SHA-256:bd8c37f6952a2130ac9ee32c53f6a660feb79bee8353c8e289eb60fdcefed91e",
              "host": "x86_64-linux-gnu",
              "archiveFileName": "avr-gcc-7.3.0-atmel3.6.1-arduino7-x86_64-pc-linux-gnu.tar.bz2",
              "url": "http://downloads.arduino.cc/tools/avr-gcc-7.3.0-atmel3.6.1-arduino7-x86_64-pc-linux-gnu.tar.bz2"
            }
          ]
        },
        {
          "name": "avrdude",
          "version": "7.2-arduino.1",
          "systems": [
            {
              "host": "arm-linux-gnueabihf",
              "url": "http://downloads.arduino.cc/tools/avrdude_7.2-arduino.1_Linux_ARMv6.tar.gz",
              "archiveFileName": "avrdude_7.2-arduino.1_Linux_ARMv6.tar.gz",
              "size": "1243922",
              "checksum": "SHA-256:b5b88e4f52c0edb861f5ae54acbd752f9ecd562a4db4d821ab8c276ee5696dab"
            },
            {
              "host": "aarch64-linux-gnu",
              "url": "http://downloads.arduino.cc/tools/avrdude_7.2-arduino.1_Linux_ARM64.tar.gz",
              "archiveFileName": "avrdude_7.2-arduino.1_Linux_ARM64.tar.gz",
              "size": "1348250",
              "checksum": "SHA-256:a3862e6a38668c2688dc0822b16c3f824612cc606259b6813bc5778d36c92ba9"
            },
            {
              "host": "x86_64-apple-darwin12",
              "url": "http://downloads.arduino.cc/tools/avrdude_7.2-arduino.1_macOS_64bit.tar.gz",
              "archiveFileName": "avrdude_7.2-arduino.1_macOS_64bit.tar.gz",
              "size": "928946",
              "checksum": "SHA-256:256cbde856714a18c11b4c99f6b00eed65e4208c92425fa9cfd75a5bdfb6ab09"
            },
            {
              "host": "x86_64-linux-gnu",
              "url": "http://downloads.arduino.cc/tools/avrdude_7.2-arduino.1_Linux_64bit.tar.gz",
              "archiveFileName": "avrdude_7.2-arduino.1_Linux_64bit.tar.gz",
              "size": "1256881",
              "checksum": "SHA-256:25e1b568757d9a58b9663e4493ffc04b9e6d690535c9c1e6c1db7d1ecffb5eff"
            },
            {
              "host": "i686-linux-gnu",
              "url": "http://downloads.arduino.cc/tools/avrdude_7.2-arduino.1_Linux_32bit.tar.gz",
              "archiveFileName": "avrdude_7.2-arduino.1_Linux_32bit.tar.gz",
              "size": "1252284",
              "checksum": "SHA-256:86a811f6ba2bebbb717a524fcff495f0ebb146abcd15d341a10d867b8e8c83fd"
            },
            {
              "host": "i686-mingw32",
              "url": "http://downloads.arduino.cc/tools/avrdude_7.2-arduino.1_Windows_32bit.tar.gz",
              "archiveFileName": "avrdude_7.2-arduino.1_Windows_32bit.tar.gz",
              "size": "1682746",
              "checksum": "SHA-256:5536c9fcb41f4a36aa55b3711a0d74943a401261b15cc8aae2473c30ff292021"
            }
          ]
        }

      ]
}
EOF