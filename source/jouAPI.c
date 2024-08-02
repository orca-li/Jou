/**
 * @copyright MIT License, 2024 (c) Orcali
 * @version 0.2.2
 */
#include <jou.h>
#include "include/jouTEMP.h"

#if jconfigLITE_VERSION == 0
#include <stdio.h>
#include <stdint.h>
#include <stdarg.h>
#include <stddef.h>
#include <string.h>

void jouPrint(char *fmt, ...);
void jouScan(char *fmt, ...);
void jouPut(char c);
int jouGetChar(void);

void jouLevelInfo(char *fmt, ...);
void jouLevelDebug(char *fmt, ...);
void jouLevelError(char *fmt, ...);
void jouLevelWarning(char *fmt, ...);

#if jconfigAPI_DUMP_HEX == 1
void jouHexDump(char *buf, size_t len);
#endif
#if jconfigAPI_DUMP_BIN == 1
void jouBinDump(char *buf, size_t len);
#endif

#if jconfigAPI_ADDONS_HOOK == 1
void jouLevelHook(char *fmt, ...);
#endif
#if jconfigAPI_ADDONS_TAG == 1
void jouTagPrint(char *tag, char *fmt, ...);
#endif 

jou_jt chj0 = {
    .print = jouPrint,
    .putc = jouPut,
    .scan = jouScan,
    .getc = jouGetChar,

    .err = jouLevelError,
    .dbg = jouLevelDebug,
    .inf = jouLevelInfo,
    .wrn = jouLevelWarning,

#if jconfigAPI_ADDONS_HOOK == 1
    .hook = jouLevelHook,
#endif    
#if jconfigAPI_ADDONS_TAG == 1
    .tag = jouTagPrint,
#endif 

#if jconfigAPI_DUMP_HEX == 1
    .hex = jouHexDump,
#endif
#if jconfigAPI_DUMP_BIN == 1
    .bin = jouBinDump,
#endif
};
#endif