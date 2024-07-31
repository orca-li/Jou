/**
 * @copyright MIT License (c) 2024 Orcali
 * @version 0.2.1
 */
#include <jou.h>
#include "include/jouTEMP.h"

#include <stdio.h>
#include <stdint.h>
#include <ctype.h>
#include <wchar.h>

static void jouPrintLevel(char *level, char *color, char *fmt, va_list *args);

#if jconfigAPI_DUMP_BIN == 1
void jouBinDump(char *buf, size_t len)
{
    __PRIVATEjouDump(jfmtDUMP_BIN, buf, len);
}

static void __STATICdumpBin(uint8_t byte)
{
    uint8_t i = 0;

#if jconfigCOLORS == 1
    if (isjdump(byte)) {
        jouINOUT_PRINT(JOU_COLOR_YELLOW);
    } else if (isjnoascii(byte)) {
        jouINOUT_PRINT(JOU_COLOR_RED);
    }
    while(i++ < 8u) {
        jouINOUT_PUTC((byte & 128) ? '1' : '0'); 
        byte <<= 1;
    }
    jouINOUT_PRINT(JOU_COLOR_RESET);
#else

    while(i++ < 8u) {
        jouINOUT_PUTC((byte & 128) ? '1' : '0'); 
        byte <<= 1;
    }
#endif
    
#if jconfigBIN_SEPARATOR == 1
    jouINOUT_PUTC(' ');
#endif
}
#endif

#if jconfigAPI_DUMP_HEX == 1
void jouHexDump(char *buf, size_t len)
{
    __PRIVATEjouDump(jfmtDUMP_HEX, buf, len);
}

inline static void __INLINEdumpHex(uint8_t byte)
{
#if jconfigCOLORS == 1
    if (isjdump(byte)) {
        jouINOUT_PRINT(JOU_COLOR_YELLOW);
    } else if (isjnoascii(byte)) {
        jouINOUT_PRINT(JOU_COLOR_RED);
    }
    jouINOUT_PRINT("%02hhx", byte);
    jouINOUT_PRINT(JOU_COLOR_RESET);
#else
    jouINOUT_PRINT("%02hhx", byte);
#endif
}
#endif

#if jconfigAPI_DUMP_HEX == 1 || jconfigAPI_DUMP_BIN == 1
static void __STATICjouPrintLine(size_t *line, uint8_t bytesInLine)
{
#if jconfigCOLORS == 1
    jouINOUT_PRINT(JOU_COLOR_YELLOW);
    jouINOUT_PRINT("%08x", *line);
    jouINOUT_PRINT(JOU_COLOR_RESET);

#else
    jouINOUT_PRINT("%08x", *line);
#endif
    jouINOUT_PRINT(":  ");

#if jconfigDUMP_DIRECTION_TOP == 1
        *line += bytesInLine;
#else
        *line -= bytesInLine;
#endif
}

inline static void __INLINEdumpASCII(uint8_t byte)
{
    if (isjdump(byte)) {
#if jconfigCOLORS == 1
        jouINOUT_PRINT(JOU_COLOR_YELLOW);
        jouINOUT_PUTC(byte);
        jouINOUT_PRINT(JOU_COLOR_RESET);
#else
        jouINOUT_PUTC(byte);
#endif
        } else {
#if jconfigCOLORS == 1
        if(isjnoascii(byte)) {
            jouINOUT_PRINT(JOU_COLOR_RED);
            jouINOUT_PUTC('.');
            jouINOUT_PRINT(JOU_COLOR_RESET);
        } else {
            jouINOUT_PUTC('.');
        }
#else
        jouINOUT_PUTC('.');
#endif
    }
}

void __PRIVATEjouDump(const char type, const char *buf, const size_t len)
{
    size_t bytesInLine = 1; /* 1 is protection against segmentation fault */
    size_t printed = 0;
#if jconfigADDRESS_COLUMN == 1
    size_t line = (size_t)buf;
#else
    size_t line = 0;
#endif

    switch (type)
    {
    case jfmtDUMP_BIN:
        bytesInLine = jconfigBIN_BYTES_IN_LINE;
        break;
#if jconfigAPI_DUMP_HEX == 1
    case jfmtDUMP_HEX:
        bytesInLine = jconfigHEX_BYTES_IN_LINE;
        break;
#endif
    }

    size_t savePrinted;
    const char *saveBuf = buf;
    while (printed < len) {
        __STATICjouPrintLine(&line, bytesInLine);

        savePrinted = printed;
        saveBuf = buf;
        uint8_t spaceSeparator = 1; /* 1 byte is index offset */
        for (size_t i = 0; i < bytesInLine; i++) {
            if (printed < len) {
                switch (type)
                {
                case jfmtDUMP_BIN:
                    __STATICdumpBin(*buf++);
                    break;
#if jconfigAPI_DUMP_HEX == 1                
                case jfmtDUMP_HEX:
                    __INLINEdumpHex(*buf++);
#endif                    
                    break;
                }
            } else {
                switch (type)
                {
                case jfmtDUMP_BIN:
                    jouINOUT_PRINT("        ");
#if jconfigBIN_SEPARATOR == 1
                    jouINOUT_PUTC(' ');
#endif
                    break;
                
                case jfmtDUMP_HEX:
                    jouINOUT_PRINT("  ");
                    break;
                }
                
            }
            
            if (spaceSeparator >= jconfigDUMP_BYTES_PER_SPACE) {    
                spaceSeparator = 0;
                jouINOUT_PUTC(' ');
            }
            spaceSeparator++;
            printed++;
        }
        printed = savePrinted;
        buf = saveBuf;

        jouINOUT_PUTC(' ');
        for (size_t i = 0; i < bytesInLine; i++) {
            if (printed < len) {
                __INLINEdumpASCII(*buf++);
            }
            printed++;
        }
        jouINOUT_PRINT("\r\n");
    }
}

#endif

static void jouPrintLevel(char *level, char *color, char *fmt, va_list *args)
{
    char buffer[jconfigPRINTJ_BUF_SIZE];

    char mrgtmp[jconfigMRGTMP_BUF_SIZE];
#if JCONFIG_COLORS == 1
    strmrg(mrgtmp, 4, color, level, JOU_COLOR_RESET, ": ");
    jouINOUT_PRINT(mrgtmp);

#else
    strmrg(mrgtmp, 2, level, ": ");
    jouINOUT_PRINT(mrgtmp)
    
#endif

    vsprintf(buffer, fmt, *args);

    jouINOUT_PRINT(buffer);
    jouINOUT_PRINT("\r\n");
}

void jouLevelWarning(char *fmt, ...)
{
    va_list args;

    va_start(args, fmt);
    jouPrintLevel(JOU_LEVEL_WARNING, JOU_COLOR_YELLOW, fmt, &args);
    va_end(args);
    
}

void jouLevelDebug(char *fmt, ...)
{
    va_list args;

    va_start(args, fmt);
    jouPrintLevel(JOU_LEVEL_DEBUG, JOU_COLOR_GREEN, fmt, &args);
    va_end(args);
}

void jouLevelInfo(char *fmt, ...)
{
    va_list args;

    va_start(args, fmt);
    jouPrintLevel(JOU_LEVEL_INFO, JOU_COLOR_BLUE, fmt, &args);
    va_end(args);
}

void jouLevelError(char *fmt, ...)
{
    va_list args;

    va_start(args, fmt);
    jouPrintLevel(JOU_LEVEL_ERROR, JOU_COLOR_RED, fmt, &args);
    va_end(args);
}

int jouGetChar(void)
{
    return JCONFIG_TUNNEL_GETC();
}

void jouScan(char *fmt, ...)
{
    char scanj_buf[jconfigSCANJ_BUF_SIZE];
    
    JCONFIG_TUNNEL_SCAN(scanj_buf);
    
    va_list args;
    va_start(args, fmt);
    vsscanf(scanj_buf, fmt, args);
    va_end(args);
}

void jouPut(char c)
{
    JCONFIG_TUNNEL_PUTC(c);
}

void jouPrint(char *fmt, ...)
{
    va_list args;
    va_start(args, fmt);
    printj(fmt, &args);
    va_end(args);
}

#if jconfigAPI_ADDONS_HOOK == 1
void jouLevelHook(char *fmt, ...)
{
    char buffer[jconfigPRINTJ_BUF_SIZE];

    char mrgtmp[jconfigMRGTMP_BUF_SIZE];
    strmrg(mrgtmp, 2, JOU_LEVEL_HOOK, ": ");
    jouINOUT_PRINT(mrgtmp);

    va_list args;
    va_start(args, fmt);
    vsprintf(buffer, fmt, args);
    va_end(args);

    for (uint8_t i = 0; i < jconfigHOOK_LENGTH; i++ ) {
        jouINOUT_PUTC(' ');
    }
    jouINOUT_PRINT(buffer);
    jouINOUT_PRINT("\r\n");
}
#endif

#if jconfigAPI_ADDONS_TAG == 1
void jouTagPrint(char *tag, char *fmt, ...)
{
    va_list args;

    char mrgtmp[jconfigMRGTMP_BUF_SIZE];
    strmrg(mrgtmp, 3, "<", tag, ">");

    va_start(args, fmt);
    jouPrintLevel(mrgtmp, JOU_COLOR_YELLOW, fmt, &args);
    va_end(args);
}
#endif