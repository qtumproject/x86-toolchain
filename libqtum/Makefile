
HDRS = include/qtum.h
CC = i386-qtum-gcc
AR = i386-qtum-ar


C_QTUM_SRC = src/qtum.c

C_QTUM_OBJS = $(subst .c,.o,$(C_QTUM_SRC))

CFLAGS ?= -Wall -O3  -Wno-unused-function
CFLAGS += -Iinclude

OUTPUTS = libqtum.a

default: build

build: $(OUTPUTS)

libqtum.a: $(C_QTUM_OBJS)
	$(AR) crs libqtum.a $(C_QTUM_OBJS)

$(C_QTUM_OBJS): $(HDRS) $(C_QTUM_SRC)
	$(CC) $(CFLAGS) -c $*.c -o $@

clean:
	rm -f $(C_QTUM_OBJS) $(OUTPUTS)



