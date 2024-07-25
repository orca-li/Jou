
#include <jou.h>

#include <stdio.h>
#include <stdint.h>
#include <stdarg.h>

static void jouLevelInfo(char *fmt, ...);
static void jouLevelDebug(char *fmt, ...);
static void jouLevelError(char *fmt, ...);
static void jouLevelWarning(char *fmt, ...);

struct JOU_BODY jou = {
    .err = jouLevelError,
    .dbg = jouLevelDebug,
    .inf = jouLevelInfo,
    .wrn = jouLevelWarning,
};

static void jouPrintLevel(char *level, char *color, char *fmt, ...)
{
    (void)level;
    (void)color;
    va_list args;
    va_start(args, fmt);
    printf(color);
    printf(level);
    printf(JOU_COLOR_RESET);
    printf(": ");
    printf(fmt);
    printf("\r\n");
    va_end(args);
}

static void jouLevelWarning(char *fmt, ...)
{
    va_list args;
    va_start(args, fmt);
    jouPrintLevel(JOU_LEVEL_WARNING, JOU_COLOR_YELLOW, fmt, args);
    va_end(args);
}

static void jouLevelDebug(char *fmt, ...)
{
    va_list args;
    va_start(args, fmt);
    jouPrintLevel(JOU_LEVEL_DEBUG, JOU_COLOR_GREEN, fmt, args);
    va_end(args);
}

static void jouLevelInfo(char *fmt, ...)
{
    va_list args;
    va_start(args, fmt);
    jouPrintLevel(JOU_LEVEL_INFO, JOU_COLOR_BLUE, fmt, args);
    va_end(args);
}

static void jouLevelError(char *fmt, ...)
{
    va_list args;
    va_start(args, fmt);
    jouPrintLevel(JOU_LEVEL_ERROR, JOU_COLOR_RED, fmt, args);
    va_end(args);
}