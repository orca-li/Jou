#include <jou.h>
#include "include/jouFMT.h"

#include <stdio.h>
#include <stdint.h>
#include <stdarg.h>
#include <stddef.h>

static void jouLevelInfo(char *fmt, ...);
static void jouLevelDebug(char *fmt, ...);
static void jouLevelError(char *fmt, ...);
static void jouLevelWarning(char *fmt, ...);
static void jouPrint(char *fmt, ...);
static void jouPut(char c);
static void jouHexDump(char *buf, size_t len, ...);

jou_jt jou = {
    /* stdio */
    .print = jouPrint,
    .put = jouPut,

    /* logs */
    .err = jouLevelError,
    .dbg = jouLevelDebug,
    .inf = jouLevelInfo,
    .wrn = jouLevelWarning,

    /* dump */
    .hex = jouHexDump,
};

/* --- METHODS -------------------------------------------------- */

static void jouHexDump(char *buf, size_t len, ...)
{
    va_list args;
    va_start(args, len);
    __PRIVATEjouHexDump(buf, len, &args);
    va_end(args);
}

static void jouPut(char c)
{
    putchar(c);
}

static void jouPrint(char *fmt, ...)
{
    va_list args;
    va_start(args, fmt);
    printf(fmt, args);
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