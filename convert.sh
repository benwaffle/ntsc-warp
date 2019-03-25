#!/bin/bash

export OCL_ICD_VENDORS=mesa # radeon is broken

WIDTH=104
HEIGHT=87

if [ $# != 1 ]; then
    echo "./convert.sh <image.jpg>"
    exit 1
fi

i=0
#CMD="convert $1 -resize ${HEIGHT}x${WIDTH}! -rotate 270 -colorspace GRAY -alpha off"
CMD="convert $1 -rotate 270 -colorspace GRAY -alpha off"

$CMD small.jpg
# BYTES=$(convert $1 -resize ${HEIGHT}x${WIDTH} -rotate 270 -colorspace GRAY -alpha off txt:- |
BYTES=$($CMD txt:- |
        grep -ve "^#"                         |
        sed -r "s/^.*gray\(([0-9]+)\).*$/\1/" |
        while read num; do
            (( $i % $WIDTH == 0 )) && printf "\n"
            (( $i % 8 == 0 )) && printf ", 0b"
            if (( $num > 125 )); then
                printf 1
            else
                printf 0
            fi
            ((i++))
        done                                  |
        sed 's/,$//')

echo "PROGMEM static const unsigned char image[] = { $WIDTH, $HEIGHT $BYTES };" > include/image.h
