#!/bin/bash

cd crtfiles
make
cd ..

mkdir -p sysroot/lib
mkdir -p sysroot/include

cp crtfiles/*.o sysroot/lib/

