CPU i386
BITS 32
SECTION .text
GLOBAL _start

EXTERN _init
EXTERN _exit_crt
EXTERN main
EXTERN __init_qtum

_start:
; what to do here?
mov esp, 0x200000 + 1024 * 6 ; init stack for Qtum stack space
call _init ;global constructors
call __init_qtum

call main ;main function

pop eax ;get return code
int 0xF0 ; VM escape API for ending execution
hlt
