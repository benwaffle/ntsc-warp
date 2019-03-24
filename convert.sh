#!/bin/bash

export OCL_ICD_VENDORS=mesa # radeon is broken

if [ $# != 1 ]; then
    echo "./convert.sh <image.jpg>"
    exit 1
fi

BYTES=$(convert $1 -resize 96x128 -rotate 270 -colorspace GRAY txt:- \
        | grep -ve "^#" \
        | sed -r "s/^.*gray\(([0-9]+)\).*$/\1/" \
        | while read num; do printf "0x%x\n" $num; done \
        | tr '\n' ',' \
        | sed 's/,$//')

echo "#include <stdint.h>
static const uint8_t image[] = { $BYTES };" > include/image.h
