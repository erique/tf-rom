//
//
// tf-rom - resident CLI command test for 'cpuspeed'
// Copyright (c) Erik Hemming
//
// This software is licensed under MIT ; see LICENSE file
//
//

#include <stdint.h>
#include <stdarg.h>

#include <proto/exec.h>

#ifdef DEBUG

static void set_uart_speed(__reg("d0") uint32_t c) = "\tmove.w\td0,$dff032\n";
static void RawPutChar(__reg("d0") uint32_t c, __reg("a6") struct ExecBase* SysBase) = "\tjsr\t-516(a6)\n";

static void raw_put_char(__reg("d0") uint32_t c, __reg("a3") struct ExecBase* SysBase)
{
    RawPutChar(c, SysBase);
}

void kprintf(const char *format, ...)
{
    va_list args;
    struct ExecBase* SysBase = *((struct ExecBase **) (4L));

    set_uart_speed(3546895/115200);

    va_start(args, format);

    RawDoFmt((STRPTR) format, (APTR) args,
             raw_put_char, (APTR) SysBase);

    va_end(args);
}

#endif
