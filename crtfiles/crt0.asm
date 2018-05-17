CPU i386
BITS 32
SECTION .text
GLOBAL _start

EXTERN _init
EXTERN _exit_crt
EXTERN main
EXTERN __init_qtum
EXTERN _onCreate

_start:
; what to do here?
mov esp, 0x200000 + 1024 * 6 ; init stack for Qtum stack space
call _init ;global constructors
call __init_qtum

mov eax, 6 ; IsCreate syscall
int 0x40
cmp eax, 1
je callCreate

callMain:
mov eax, 0
call main ;main function

exit:
pop eax ;get return code
int 0xF0 ; VM escape API for ending execution
hlt

callCreate:

call _onCreate
cmp eax, 0
jne exit ;error code, so exit with error
jmp callMain

