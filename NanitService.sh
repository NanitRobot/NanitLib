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
          ],
          "toolsDependencies": [
            {
              "packager": "arduino",
              "name": "avr-gcc",
              "version": "7.3.0-atmel3.6.1-arduino7"
            },
            {
              "packager": "NanitService",
              "name": "avrdude",
              "version": "7.2-arduino.1"
            },
            {
              "packager": "arduino",
              "name": "arduinoOTA",
              "version": "1.3.0"
            }
          ]
        }
      ],
      "tools": [
        {
          "name": "avrdude",
          "version": "7.1-arduino.1",
          "systems": [
            {
              "size": "1161418",
              "checksum": "SHA-256:6c842593530e8ee463760fca6c6244eeff5718fac6ed5798386a2d9704735fb5",
              "host": "arm-linux-gnueabihf",
              "archiveFileName": "avrdude_7.1-arduino.1_Linux_ARMv6.tar.gz",
              "url": "http://downloads.arduino.cc/tools/avrdude_7.1-arduino.1_Linux_ARMv6.tar.gz"
            },
            {
              "size": "1261196",
              "checksum": "SHA-256:37743def85b0fa70b566797d889e6d649f644ad7fa67a3e151b6e61aba9a0d0a",
              "host": "aarch64-linux-gnu",
              "archiveFileName": "avrdude_7.1-arduino.1_Linux_ARM64.tar.gz",
              "url": "http://downloads.arduino.cc/tools/avrdude_7.1-arduino.1_Linux_ARM64.tar.gz"
            },
            {
              "size": "834101",
              "checksum": "SHA-256:436a7a5f467774cdd39683d2226314ba90485b0b08c629602004f4bbfdddf575",
              "host": "x86_64-apple-darwin12",
              "archiveFileName": "avrdude_7.1-arduino.1_macOS_64bit.tar.gz",
              "url": "http://downloads.arduino.cc/tools/avrdude_7.1-arduino.1_macOS_64bit.tar.gz"
            },
            {
              "size": "1169286",
              "checksum": "SHA-256:11f6c709d9f950e35993ca27ed870a86711d7093255a9e4b4463160f1778fd19",
              "host": "x86_64-linux-gnu",
              "archiveFileName": "avrdude_7.1-arduino.1_Linux_64bit.tar.gz",
              "url": "http://downloads.arduino.cc/tools/avrdude_7.1-arduino.1_Linux_64bit.tar.gz"
            },
            {
              "size": "1170712",
              "checksum": "SHA-256:f5eff5141c9385b56ca3be780453149c912abf7b5bf87de8398f661a1369d305",
              "host": "i686-linux-gnu",
              "archiveFileName": "avrdude_7.1-arduino.1_Linux_32bit.tar.gz",
              "url": "http://downloads.arduino.cc/tools/avrdude_7.1-arduino.1_Linux_32bit.tar.gz"
            },
            {
              "size": "1591591",
              "checksum": "SHA-256:35d3b917573a91b7a7e5805919a1fa3bc033541e2941b710bfc627071c738731",
              "host": "i686-mingw32",
              "archiveFileName": "avrdude_7.1-arduino.1_Windows_32bit.tar.gz",
              "url": "http://downloads.arduino.cc/tools/avrdude_7.1-arduino.1_Windows_32bit.tar.gz"
            }
          ]
        },
        {
          "name": "avrdude",
          "version": "7.2-arduino.1",
          "systems": [
            {
              "size": "1243922",
              "checksum": "SHA-256:b5b88e4f52c0edb861f5ae54acbd752f9ecd562a4db4d821ab8c276ee5696dab",
              "host": "arm-linux-gnueabihf",
              "archiveFileName": "avrdude_7.2-arduino.1_Linux_ARMv6.tar.gz",
              "url": "http://downloads.arduino.cc/tools/avrdude_7.2-arduino.1_Linux_ARMv6.tar.gz"
            },
            {
              "size": "1348250",
              "checksum": "SHA-256:a3862e6a38668c2688dc0822b16c3f824612cc606259b6813bc5778d36c92ba9",
              "host": "aarch64-linux-gnu",
              "archiveFileName": "avrdude_7.2-arduino.1_Linux_ARM64.tar.gz",
              "url": "http://downloads.arduino.cc/tools/avrdude_7.2-arduino.1_Linux_ARM64.tar.gz"
            },
            {
              "size": "928946",
              "checksum": "SHA-256:256cbde856714a18c11b4c99f6b00eed65e4208c92425fa9cfd75a5bdfb6ab09",
              "host": "x86_64-apple-darwin12",
              "archiveFileName": "avrdude_7.2-arduino.1_macOS_64bit.tar.gz",
              "url": "http://downloads.arduino.cc/tools/avrdude_7.2-arduino.1_macOS_64bit.tar.gz"
            },
            {
              "size": "1256881",
              "checksum": "SHA-256:25e1b568757d9a58b9663e4493ffc04b9e6d690535c9c1e6c1db7d1ecffb5eff",
              "host": "x86_64-linux-gnu",
              "archiveFileName": "avrdude_7.2-arduino.1_Linux_64bit.tar.gz",
              "url": "http://downloads.arduino.cc/tools/avrdude_7.2-arduino.1_Linux_64bit.tar.gz"
            },
            {
              "size": "1252284",
              "checksum": "SHA-256:86a811f6ba2bebbb717a524fcff495f0ebb146abcd15d341a10d867b8e8c83fd",
              "host": "i686-linux-gnu",
              "archiveFileName": "avrdude_7.2-arduino.1_Linux_32bit.tar.gz",
              "url": "http://downloads.arduino.cc/tools/avrdude_7.2-arduino.1_Linux_32bit.tar.gz"
            },
            {
              "size": "1682746",
              "checksum": "SHA-256:5536c9fcb41f4a36aa55b3711a0d74943a401261b15cc8aae2473c30ff292021",
              "host": "i686-mingw32",
              "archiveFileName": "avrdude_7.2-arduino.1_Windows_32bit.tar.gz",
              "url": "http://downloads.arduino.cc/tools/avrdude_7.2-arduino.1_Windows_32bit.tar.gz"
            }
          ]
        }
      ]
    }
  ]
}
EOF