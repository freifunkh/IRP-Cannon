#!/bin/bash
DIR=$(cd `dirname $0` && pwd)

rm $DIR/ffhweb.h
rm -r $DIR/out

mkdir -p $DIR/web
mkdir -p $DIR/out/b64


for filepath in $DIR/web/images/*; do
	filename=$(basename $filepath)
	base64 -w 0 $filepath > $DIR/out/b64/$filename.b64
done
