#include <jou.h>
#include "include/jouTEMP.h"

#include <stdio.h>
#include <stdint.h>
#include <stdarg.h>
#include <stddef.h>
#include <string.h>

static void jouLevelInfo(char *fmt, ...);
static void jouLevelDebug(char *fmt, ...);
static void jouLevelError(char *fmt, ...);
static void jouLevelWarning(char *fmt, ...);
static void jouPrint(char *fmt, ...);
static void jouPut(char c);
static void jouHexDump(char *buf, size_t len);
static void jouMergeLines(char *buf, char *add, ...);
static void jouScan(char *fmt, ...);
static int jouGetChar(void);

jou_jt chj0 = {
    /* stdio */
    .print = jouPrint,
    .putc = jouPut,
    .scan = jouScan,
    .getc = jouGetChar,

    /* logs */
    .err = jouLevelError,
    .dbg = jouLevelDebug,
    .inf = jouLevelInfo,
    .wrn = jouLevelWarning,

    /* dump */
    .hex = jouHexDump,
    .merge = jouMergeLines,
};

/* --- METHODS -------------------------------------------------- */

static int jouGetChar(void)
{
    return JCONFIG_TUNNEL_GETC();
}

static void jouScan(char *fmt, ...)
{
    char scanj_buf[JCONFIG_SCANJ_BUF_SIZE];
    
    JCONFIG_TUNNEL_SCAN(scanj_buf);
    
    va_list args;
    va_start(args, fmt);
    vsscanf(scanj_buf, fmt, args);
    va_end(args);
}

static void jouMergeLines(char *buf, char *add, ...)
{
    va_list args;
    va_start(args, add);

    va_end(args);
}

static void jouHexDump(char *buf, size_t len)
{
    __PRIVATEjouHexDump(buf, len);
}

static void jouPut(char c)
{
    JCONFIG_TUNNEL_PUTC(c);
}

static void jouPrint(char *fmt, ...)
{
    va_list args;
    va_start(args, fmt);
    printj(fmt, &args);
    va_end(args);
}

static void jouPrintLevel(char *level, char *color, char *fmt, va_list *args)
{
    char buffer[256];

    printf(color);
    printf(level);
    printf(JOU_COLOR_RESET);
    printf(": ");

    vsprintf(buffer, fmt, *args);

    fputs(buffer, stdout);
    printf("\r\n");
}


/* --- TEMPLATES -------------------------------------------------- */
static void jouLevelWarning(char *fmt, ...)
{
    va_list args;

    va_start(args, fmt);
    jouPrintLevel(JOU_LEVEL_WARNING, JOU_COLOR_YELLOW, fmt, &args);
    va_end(args);
    
}

static void jouLevelDebug(char *fmt, ...)
{
    va_list args;

    va_start(args, fmt);
    jouPrintLevel(JOU_LEVEL_DEBUG, JOU_COLOR_GREEN, fmt, &args);
    va_end(args);
}

static void jouLevelInfo(char *fmt, ...)
{
    va_list args;

    va_start(args, fmt);
    jouPrintLevel(JOU_LEVEL_INFO, JOU_COLOR_BLUE, fmt, &args);
    va_end(args);
}

static void jouLevelError(char *fmt, ...)
{
    va_list args;

    va_start(args, fmt);
    jouPrintLevel(JOU_LEVEL_ERROR, JOU_COLOR_RED, fmt, &args);
    va_end(args);
}