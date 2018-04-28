
HDRS = include/qtum.h
CC = i386-qtum-gcc
AR = i386-qtum-ar
AS = i386-qtum-as


C_QTUM_SRC = src/qtum.c
C_QTUM_OBJS = $(subst .c,.o,$(C_QTUM_SRC))

S_QTUM_SRC = src/syscall.S
S_QTUM_OBJS = $(subst .S,.o,$(S_QTUM_SRC))

CFLAGS ?= -Wall -O3  -Wno-unused-function
CFLAGS += -Iinclude

OUTPUTS = libqtum.a

default: build

build: $(OUTPUTS)

libqtum.a: $(C_QTUM_OBJS) $(S_QTUM_OBJS)
	$(AR) crs libqtum.a $(C_QTUM_OBJS) $(S_QTUM_OBJS)

$(C_QTUM_OBJS): $(HDRS) $(C_QTUM_SRC)
	$(CC) $(CFLAGS) -c $*.c -o $@

$(S_QTUM_OBJS): $(HDRS) $(S_QTUM_SRC)
	$(AS) $*.S -o $@

clean:
	rm -f $(C_QTUM_OBJS) $(OUTPUTS) $(S_QTUM_OBJS)



