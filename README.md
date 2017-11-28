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

First of all, if building from scratch you will first need to build a freestanding i386 compiler. This is a compiler that makes no assumptions about it's operating environment and is normally used for kernel and operating system development. In our case, we only need the i386 compiler to initially bootstrap the environment required to later build. After we have built our libc, we can compile i386-qtum-gcc and then use it for libc compilation.

Follow this guide to build a freestanding compiler. Make sure to use the target i386-elf and not i686-elf, since x86Lib doesn't yet support all i686 opcodes (or i386 for that matter.. but anyway)

Once you get to the point that you can run i386-elf-gcc, you are ready to build our libc. Right now our libc is built from a fork from an open source project. This provides all of the required functions to compile libgcc (which is thus required to compile GCC itself). To build our libc:

    git clone https://github.com/qtumproject/FsLibc
    cmake -DCMAKE_BUILD_TYPE=Release -DCMAKE_TOOLCHAIN_FILE=cross-toolchain.cmake -DCMAKE_INSTALL_PREFIX=$HOME/x86-toolchain/sysroot/usr .
    make -C libc
    make -C libc install

**Caution!!!** Be careful when running `make -C libc install`. If it gives a permission denied error, do NOT use sudo. You most likely made a mistake and it is attempting to overwrite your system's header and library files, which will break your system most likely.

## Preparing sysroot

The next step after compiling libc is to prepare the sysroot. This can be done by calling prepare_sysroot.h. This will compile the necessary crt files for linking and also creates some header files that libgcc expects to exist. 

## Building i386-qtum-gcc

You must first build binutils. Look in build.sh for a template script to follow. This should probably work, but it is not intended to be perfectly copy-pasteable since systems vary. 

After building and installing into your PREFIX, you should be able to call `i386-qtum-gcc -v` and get some version information about the compiler. You've done it!

