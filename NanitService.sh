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
      "maintainer": "NanitRobots",
      "websiteURL": "${WEB_SITE_URL}",
      "email": "${EMAIL}",
      "help": {
        "online": "${HELP_ONLINE}"
      },
      "platforms": [
                {
          "name": "NanitService",
          "architecture": "avr",
          "version": "$(date +%y.%j)",
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
              "name": "avrdude",
              "version": "6.3.0-arduino17"
            }
          ]
}
EOF