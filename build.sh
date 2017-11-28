#!/bin/bash
export PREFIX="$HOME/opt/cross"
export TARGET=i386-qtum
export PATH="$PREFIX/bin:$PATH"
export SYSROOT="$HOME/x86-toolchain/sysroot"

#Not really building this file to use unmodified, but should provide good guidance

#NOTE: You must build libc before compiling gcc! This can be done by building a freestanding i386-elf compiler.
#To do this, use similar commands as these, but
#remove the --with-sysroot option, and change the target to i386-elf

mkdir build-binutils
cd build-binutils
../binutils-2.29/configure --target=i386-qtum --prefix="$PREFIX" --with-sysroot="$SYSROOT" --disable-werror
make
make install

cd ..
mkdir build-gcc
cd build-gcc
../gcc-7.2.0/configure --target=i386-qtum --prefix="$PREFIX" --with-sysroot="$SYSROOT" --enable-languages=c
make all-gcc
make all-target-libgcc
make install-gcc
make install-target-libgcc

