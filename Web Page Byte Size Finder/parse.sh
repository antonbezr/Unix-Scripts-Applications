#!/bin/bash

if [ $# -lt 1 ]; then
   echo "Insufficient number of arguements"
   exit 1
fi

if [ ! -e "$2" ]; then
   echo "Error: input file does not exist"
   exit 1
fi

egrep -o '<strong><a href=\"http://.*\">' "$2" | sed 's/^\(<strong><a href=\"\)*//' | sed -e 's/\(\">\)*$//g' > "$1"

exit 0
