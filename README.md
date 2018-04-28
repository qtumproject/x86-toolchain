# Toolchain targeted for Qtum's x86 VM

This is a GNU GCC and friends toolchain modified to support the "i386-qtum" target. This means that after building this, it is possible to simply do:

    i386-qtum-gcc test.c -o contract

And the "contract" file that is outputed will be capable of being used with the x86Lib testbench program (and later deployed to Qtum's blockchain)

Note: even though x86Lib will later support i686, right now there is only i386 support.. so only target this! 

Resources:

* http://wiki.osdev.org/OS_Specific_Toolchain
* http://wiki.osdev.org/GCC_Cross-Compiler
* http://wiki.osdev.org/Hosted_GCC_Cross-Compiler
* http://wiki.osdev.org/Meaty_Skeleton#System_Root
* http://wiki.osdev.org/Creating_a_C_Library

## Building It

The requirements for building the QtumOS compiler is:

* GCC sources
* pre-compiled minimal version of libc
* pre-compiled minimal version fo libqtum
* "sysroot" properly constructed with crt files assembled

In order to compile the minimal versions of libc, a freestanding generic compiler is required. This can be built as so:

    #!/bin/bash
    export PREFIX="$HOME/opt/cross"
    export TARGET=i386-elf
    export PATH="$PREFIX/bin:$PATH"
    export SYSROOT="$HOME/x86-compiler/sysroot" #change if needed

    mkdir build-binutils
    cd build-binutils
    ../binutils-2.29/configure --target="$TARGET" --prefix="$PREFIX" --disable-werror
    make
    make install
    cd ..
    mkdir build-gcc
    cd build-gcc
    ../gcc-7.2.0/configure --target="$TARGET" --prefix="$PREFIX" --enable-languages=c
    make all-gcc
    make all-target-libgcc
    make install-gcc
    make install-target-libgcc

A freestanding compiler is useful to have if doing development on these internals and causes no conflicts, so it is not necessary to remove or uninstall it afterwards.

With our freestanding compiler we will compile a very minimal libc. GCC actually requires some minimal functions of libc to be included, even if they do not actually work or do anything. The freestanding compilers are invoked by using `i386-elf-gcc`, `i386-elf-ld`, etc. 

In order to download and compile the minimal libc, use this script:

    git clone https://github.com/qtumproject/FsLibc
    cmake -DCMAKE_BUILD_TYPE=Release -DCMAKE_TOOLCHAIN_FILE=cross-toolchain.cmake -DCMAKE_INSTALL_PREFIX=$SYSROOT/usr .
    make -C libc
    make -C libc install

**CAUTION!!!** Be careful when running `make -C libc install`. If it gives a permission denied error, do NOT use sudo. You most likely made a mistake and it is attempting to overwrite your system's header and library files, which will break your system most likely. Make sure you did everything properly and why you are getting a permission denied error! 

We now have a minimal libc that is capable of being used to build our QtumOS GCC. Next, we need to prepare the rest of the sysroot:

    cd crtfiles
    make
    cd ..
    mkdir -p $SYSROOT/usr/lib
    mkdir -p $SYSROOT/usr/include
    cp crtfiles/*.o $SYSROOT/usr/lib/
    cp -r includes/* $SYSROOT/usr/include/

We now have our crt files used for bootstrapping and other invisible code compiled and into the proper place. Now, we can compile the QtumOS compiler. This is almost exactly like compiling the freestanding compiler.

    #!/bin/bash
    export PREFIX="$HOME/opt/cross"
    export TARGET=i386-qtum
    export PATH="$PREFIX/bin:$PATH"

    rm -rf build-binutils
    mkdir build-binutils
    cd build-binutils
    ../binutils-2.29/configure --target=i386-qtum --prefix="$PREFIX" --with-sysroot="$SYSROOT" --disable-werror
    make
    make install

    cd ..
    rm -rf build-gcc
    mkdir build-gcc
    cd build-gcc
    ../gcc-7.2.0/configure --target=i386-qtum --prefix="$PREFIX" --with-sysroot="$SYSROOT" --enable-languages=c
    make all-gcc
    make all-target-libgcc
    make install-gcc
    make install-target-libgcc

Now we have our QtumOS compiler, however if you try to compile a program it will complain with "unable to find libqtum.a" or similar. We need to compile libqtum and place it in our sysroot. This can be done as so (this will be changed later since we will have a separate and full version of libqtum)

    cd libqtum
    make
    cd ..

    cp libqtum/libqtum.a $SYSROOT/usr/lib/
    cp libqtum/include/* $SYSROOT/usr/include/


After building and installing into your PREFIX, you should be able to call `i386-qtum-gcc -v` and get some version information about the compiler. And finally, for the full test you should be able to compile a hello world program and it actually compile to a .elf file. 

