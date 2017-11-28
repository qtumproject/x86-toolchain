CPU i386
BITS 32

SECTION .init
   ; gcc will nicely put the contents of crtend.o's .init section here. 
   pop ebp
   ret

SECTION .fini
   ; gcc will nicely put the contents of crtend.o's .fini section here. 
   pop ebp
   ret