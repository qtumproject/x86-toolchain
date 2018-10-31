CPU i386
BITS 32
SECTION .text
GLOBAL _start

EXTERN _init
EXTERN _exit_crt
EXTERN main
EXTERN __init_qtum
EXTERN onCreate

_start:
mov esp, 0x200000 + 1024 * 6 ; init stack for Qtum stack space
call _init ;global constructors
call __init_qtum ;internal libqtum setup

mov eax, [0xD0000004] ;ExecDataABI.isCreate
cmp eax, 1
je callCreate

callMain:
mov eax, 0
call main ;main function

exit:
; eax is return code
int 0xF0 ; VM escape API for ending execution
hlt ; should never reach this

callCreate:
mov eax, 0
call onCreate
jmp exit

