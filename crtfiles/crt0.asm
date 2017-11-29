CPU i386
BITS 32
SECTION .text
GLOBAL _start

EXTERN _init
EXTERN _exit_crt
EXTERN main

_start:
; what to do here?
call _init ;global constructors

call main ;main function

pop eax ;get return code
out 0xF0, eax ; VM escape API for ending execution
hlt
