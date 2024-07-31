/**
 * @copyright MIT License (c) 2024 Orcali
 * @version 0.2
 */
#include <jou.h>
#include "include/jouTEMP.h"

#include <stdio.h>
#include <stdint.h>
#include <ctype.h>
#include <wchar.h>

static void __STATICjouPrintLine(size_t *line, uint8_t bytesInLine)
{
#if jconfigCOLORS == 1
    jou.print(JOU_COLOR_YELLOW);
    jou.print("%08x", *line);
    jou.print(JOU_COLOR_RESET);

#else
    jou.print("%08x", *line);
#endif
    jou.print(":  ");

#if jconfigDUMP_DIRECTION_TOP == 1
        *line += bytesInLine;
#else
        *line -= bytesInLine;
#endif
}

static void __STATICdumpBin(uint8_t byte)
{
    uint8_t i = 0;

#if jconfigCOLORS == 1
    if (isjdump(byte)) {
        jou.print(JOU_COLOR_YELLOW);
    } else if (isjnoascii(byte)) {
        jou.print(JOU_COLOR_RED);
    }
    
    while(i++ < 8u) {
        jou.putc((byte & 128) ? '1' : '0'); 
        byte <<= 1;
    }

    jou.print(JOU_COLOR_RESET);
#else
    while(i++ < 8u) {
        jou.putc((byte & 128) ? '1' : '0'); 
        byte <<= 1;
    }

#endif

    
#if jconfigBIN_SEPARATOR == 1
    jou.putc(' ');
#endif
}

inline static void __INLINEdumpHex(uint8_t byte)
{
#if jconfigCOLORS == 1
    if (isjdump(byte)) {
        jou.print(JOU_COLOR_YELLOW);
    } else if (isjnoascii(byte)) {
        jou.print(JOU_COLOR_RED);
    }
    jou.print("%02hhx", byte);
    jou.print(JOU_COLOR_RESET);
#else
    jou.print("%02hhx", byte);
#endif
}

inline static void __INLINEdumpASCII(uint8_t byte)
{
    if (isjdump(byte)) {
#if jconfigCOLORS == 1
        jou.print(JOU_COLOR_YELLOW);
        jou.putc(byte);
        jou.print(JOU_COLOR_RESET);
#else
        jou.putc(byte);
#endif
        } else {
#if jconfigCOLORS == 1
        if(isjnoascii(byte)) {
            jou.print(JOU_COLOR_RED);
            jou.putc('.');
            jou.print(JOU_COLOR_RESET);
        } else {
            jou.putc('.');
        }
#else
        jou.putc('.');
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
    
    case jfmtDUMP_HEX:
        bytesInLine = jconfigHEX_BYTES_IN_LINE;
        break;
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
                
                case jfmtDUMP_HEX:
                    __INLINEdumpHex(*buf++);
                    break;
                }
            } else {
                switch (type)
                {
                case jfmtDUMP_BIN:
                    jou.print("        ");
#if jconfigBIN_SEPARATOR == 1
                    jou.putc(' ');
#endif
                    break;
                
                case jfmtDUMP_HEX:
                    jou.print("  ");
                    break;
                }
                
            }
            
            if (spaceSeparator >= jconfigDUMP_BYTES_PER_SPACE) {    
                spaceSeparator = 0;
                jou.putc(' ');
            }
            spaceSeparator++;
            printed++;
        }
        printed = savePrinted;
        buf = saveBuf;

        jou.putc(' ');
        for (size_t i = 0; i < bytesInLine; i++) {
            if (printed < len) {
                __INLINEdumpASCII(*buf++);
            }
            printed++;
        }
        jou.print("\r\n");
    }
}