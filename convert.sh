#!/bin/bash

export OCL_ICD_VENDORS=mesa # radeon is broken

#WIDTH=128
#HEIGHT=96
WIDTH=32
HEIGHT=96

if [ $# != 1 ]; then
    echo "./convert.sh <image.jpg>"
    exit 1
fi

i=0
BYTES=$(convert $1 -resize ${HEIGHT}x${WIDTH} -rotate 270 -colorspace GRAY -alpha off txt:- |
        grep -ve "^#"                         |
        sed -r "s/^.*gray\(([0-9]+)\).*$/\1/" |
        while read num; do
            printf "0x%x, " $num
            ((i++))
            (( $i % $WIDTH == 0 )) && printf "\n"
        done                                  |
        sed 's/,$//')

echo "PROGMEM static const unsigned char image[] = { $WIDTH, $HEIGHT, $BYTES };" > include/image.h
