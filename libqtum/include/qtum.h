#ifndef QTUM_H
#define QTUM_H

#include <stdint.h>

//out port VM escape APIs
#define QTUM_OUT_PUTC 0
#define QTUM_DUMP_MEMORY 0xF3

//in port VM escape APIs
#define QTUM_IN_GETC 0x30


static void outd(uint16_t port, uint32_t val)
{
    asm volatile ( "out %0, %1" : : "a"(val), "Nd"(port) );
}

static uint32_t ind(uint16_t port)
{
    uint32_t ret;
    asm volatile ( "in %1, %0" : "=a"(ret) : "Nd"(port) );
    return ret;
}
static void outW(uint16_t port, uint16_t val)
{
    asm volatile ( "out %0, %1" : : "a"(val), "Nd"(port) );
}

static uint16_t inW(uint16_t port)
{
    uint16_t ret;
    asm volatile ( "in %1, %0" : "=a"(ret) : "Nd"(port) );
    return ret;
}
static void outb(uint16_t port, uint8_t val)
{
    asm volatile ( "out %0, %1" : : "a"(val), "Nd"(port) );
}

static uint8_t inb(uint16_t port)
{
    uint8_t ret;
    asm volatile ( "in %1, %0" : "=a"(ret) : "Nd"(port) );
    return ret;
}

//called internally to initialize libc, etc
void __init_qtum();

#endif