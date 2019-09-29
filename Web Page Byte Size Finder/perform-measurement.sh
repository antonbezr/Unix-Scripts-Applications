#!/bin/bash

if [ $# -lt 1 ]; then
   echo "Insufficient number of arguements"
   exit 1
fi

tempFile=$(mktemp -p '/tmp' -t 'tempXXX')

wget -t 1 --timeout=60 "$1" -O "$tempFile" -o /dev/null
ls -l "$tempFile" | cut -d " " -f5
rm -rf "$tempFile"

exit 0

