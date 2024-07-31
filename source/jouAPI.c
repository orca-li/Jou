/**
 * @copyright MIT License (C) 2024 Orcali
 * @version 0.2
 */
#include <jou.h>
#include "include/jouTEMP.h"

#include <stdio.h>
#include <stdint.h>
#include <stdarg.h>
#include <stddef.h>
#include <string.h>

static void jouPrint(char *fmt, ...);
static void jouScan(char *fmt, ...);
static void jouPut(char c);
static int jouGetChar(void);

static void jouLevelInfo(char *fmt, ...);
static void jouLevelDebug(char *fmt, ...);
static void jouLevelError(char *fmt, ...);
static void jouLevelWarning(char *fmt, ...);

static void jouHexDump(char *buf, size_t len);
static void jouBinDump(char *buf, size_t len);

static void jouLevelHook(char *fmt, ...);
static void jouTagPrint(char *tag, char *fmt, ...);

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

    /* addons */
    .hook = jouLevelHook,
    .tag = jouTagPrint,

    /* dump */
    .hex = jouHexDump,
    .bin = jouBinDump,
};

/* --- METHODS -------------------------------------------------- */

static int jouGetChar(void)
{
    return JCONFIG_TUNNEL_GETC();
}

static void jouScan(char *fmt, ...)
{
    char scanj_buf[jconfigSCANJ_BUF_SIZE];
    
    JCONFIG_TUNNEL_SCAN(scanj_buf);
    
    va_list args;
    va_start(args, fmt);
    vsscanf(scanj_buf, fmt, args);
    va_end(args);
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
    char buffer[jconfigPRINTJ_BUF_SIZE];

    char mrgtmp[jconfigMRGTMP_BUF_SIZE];
#if JCONFIG_COLORS == 1
    strmrg(mrgtmp, 4, color, level, JOU_COLOR_RESET, ": ");
    jou.print(mrgtmp);

#else
    strmrg(mrgtmp, 2, level, ": ");
    jou.print(mrgtmp)
    
#endif

    vsprintf(buffer, fmt, *args);

    jou.print(buffer);
    jou.print("\r\n");
}

static void jouBinDump(char *buf, size_t len)
{
    __PRIVATEjouDump(jfmtDUMP_BIN, buf, len);
}

static void jouHexDump(char *buf, size_t len)
{
    __PRIVATEjouDump(jfmtDUMP_HEX, buf, len);
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

static void jouLevelHook(char *fmt, ...)
{
    char buffer[jconfigPRINTJ_BUF_SIZE];

    char mrgtmp[jconfigMRGTMP_BUF_SIZE];
    strmrg(mrgtmp, 2, JOU_LEVEL_HOOK, ": ");
    jou.print(mrgtmp);

    va_list args;
    va_start(args, fmt);
    vsprintf(buffer, fmt, args);
    va_end(args);

    for (uint8_t i = 0; i < jconfigHOOK_LENGTH; i++ ) {
        jou.putc(' ');
    }
    jou.print(buffer);
    jou.print("\r\n");
}

static void jouTagPrint(char *tag, char *fmt, ...)
{
    va_list args;

    char mrgtmp[jconfigMRGTMP_BUF_SIZE];
    strmrg(mrgtmp, 3, "<", tag, ">");

    va_start(args, fmt);
    jouPrintLevel(mrgtmp, JOU_COLOR_YELLOW, fmt, &args);
    va_end(args);
}