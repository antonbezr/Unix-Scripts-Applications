#!/bin/bash

if [ ! -e "$2" ]; then
   echo "Error: input file does not exist"
   exit 1
fi

rank=0

rm -rf "$1"

while read p; do
  echo "Performing byte-size measurement on $p"
  let rank=rank+1
  size=$(./perform-measurement.sh "$p")
  if [ "$size" -gt 0 ]; then
  	echo "$rank $p $size" >> "$1"
  	echo "...successful"
  else
  	echo "...failure"
  fi
done <"$2"

exit 0
