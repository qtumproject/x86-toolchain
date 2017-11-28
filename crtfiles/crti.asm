CPU i386
BITS 32
SECTION .init
GLOBAL _init
_init:
    push ebp
    mov ebp, esp
; gcc will nicely put the contents of crtbegin.o's .init section here.

SECTION .fini
GLOBAL _fini
_fini:
   push ebp
   mov ebp, esp
; gcc will nicely put the contents of crtbegin.o's .fini section here. */