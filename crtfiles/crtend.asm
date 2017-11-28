CPU i386
BITS 32
SECTION .text

GLOBAL _exit_crt

EXTERN _fini
_exit_crt:
call _fini
pop eax
pop eax ;get return code
out 0xF0, eax ; VM escape API for ending execution
hlt