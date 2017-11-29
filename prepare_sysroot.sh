#!/bin/bash

cd crtfiles
make
cd ..

mkdir -p sysroot/usr/lib
mkdir -p sysroot/usr/include

cp crtfiles/*.o sysroot/usr/lib/

cp -r includes/* sysroot/usr/include/

#it's expected this will error.. it's ok to ignore, run this script again after building the i386-qtum compiler
cd libqtum
make
cd ..

cp libqtum/libqtum.a sysroot/usr/lib/
cp libqtum/include/* sysroot/usr/include/