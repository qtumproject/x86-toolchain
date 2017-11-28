CPU i386
BITS 32
SECTION .text

GLOBAL _exit_crt

EXTERN _fini
_exit_crt:
call _fini
