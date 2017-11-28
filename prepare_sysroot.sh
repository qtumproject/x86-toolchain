#!/bin/bash

cd crtfiles
make
cd ..

mkdir -p sysroot/usr/lib
mkdir -p sysroot/usr/include

cp crtfiles/*.o sysroot/usr/lib/

