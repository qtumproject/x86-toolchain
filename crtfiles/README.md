# CRT files

These are used by GCC (and others) to bootstrap the execution environment. 

Order: crt0.o, crti.o, crtbegin.o, your-program-foo.o, your-program-bar.o, crtend.o, crtn.o.

Details:

* crtbegin/crtend calls global constructors and destructors.
* crti is for initialization? 
* crtn is for calling exit and ending execution
* crt0 boot straps the execution environement