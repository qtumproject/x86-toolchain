/* Useful if you wish to make target-specific GCC changes. */
#undef TARGET_QTUM
#define TARGET_QTUM 1
 
/* Default arguments you want when running your
   i686-myos-gcc/x86_64-myos-gcc toolchain */
#define LIB_SPEC "-lc" /* link against C standard library */
 
/* Files that are linked before user code.
   The %s tells GCC to look for these files in the library directory. */
#define STARTFILE_SPEC "crt0.o%s crti.o%s crtbegin.o%s"
 
/* Files that are linked after user code. */
#define ENDFILE_SPEC "crtend.o%s crtn.o%s"
 
/* Don't automatically add extern "C" { } around header files. */
#undef  NO_IMPLICIT_EXTERN_C
#define NO_IMPLICIT_EXTERN_C 1
 
/* Additional predefined macros. */
#undef TARGET_OS_CPP_BUILTINS
#define TARGET_OS_CPP_BUILTINS()      \
  do {                                \
    builtin_define ("__qtum__");      \
    builtin_define ("__qtum_x86__");  \
    builtin_assert ("system=qtum");   \
  } while(0);