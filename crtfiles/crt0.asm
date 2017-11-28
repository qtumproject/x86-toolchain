CPU i386
BITS 32
SECTION .text
GLOBAL _start

EXTERN _init
EXTERN _exit_crt
EXTERN _main

_start:
; what to do here?
call _init ;global constructors

call _main ;main function

call _exit_crt
