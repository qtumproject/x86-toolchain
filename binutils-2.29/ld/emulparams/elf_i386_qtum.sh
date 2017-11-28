. ${srcdir}/emulparams/elf_i386.sh
GENERATE_SHLIB_SCRIPT=no
GENERATE_PIE_SCRIPT=no
TEXT_BASE_ADDRESS=0x1008
#TEXT_START_SYMBOLS=_start
#ENTRY=_start
DATA_ADDR=0x100000
OTHER_BSS_SYMBOLS='__bss_start__ = .;'
OTHER_BSS_END_SYMBOLS='_bss_end__ = . ; __bss_end__ = . ;'
OTHER_END_SYMBOLS='__end__ = . ;'
OTHER_DATA_SYMBOLS='__data_start__ = .;'
OTHER_DATA_END_SYMBOLS='_data_end__ = . ; __data_end__ = . ;'
TEXT_SIZE=64K
DATA_SIZE=32K
EMBEDDED=yes
