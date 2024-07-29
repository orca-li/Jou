/**
 * @copyright MIT License (C) 2024 Orcali
 * @version v0.1.1
 */
#include <jou.h>
#include "include/jouTEMP.h"

#include <stdio.h>
#include <stdint.h>
#include <ctype.h>
#include <wchar.h>

#if defined(JCONFIG_COLORS)
void __PRIVATEjouHexDump(char *buf, size_t len)
{
#if JCONFIG_ADDRESS_COLUMN == 1
    size_t line = (size_t)buf;
#else
    size_t line = 0;
#endif
    size_t i = 0;
    size_t itemp;

    char *pHEX, *pASCII;
    pHEX = pASCII = buf;

    while (i < len) {
#if JCONFIG_COLORS == 1
        jou.print(JOU_COLOR_YELLOW);
        jou.print("%08x", line);
        jou.print(JOU_COLOR_RESET);

#else
        jou.print("%08x", line);
#endif
        jou.print(":  ");

        itemp = i;
        for (size_t j = 0; j < JCONFIG_HEXDUMP_BYTES_IN_LINE / 2; j++) {
            for (size_t k = 0; k < JCONFIG_HEXDUMP_BYTES_PER_SPACE; k++) {
                if (itemp >= len) {
                    jou.print("  ");
                } else {
#if JCONFIG_COLORS == 1
                    if (isjdump(*pHEX)) {
                        jou.print(JOU_COLOR_YELLOW);
                    } else if (isjnoascii(*pHEX)) {
                        jou.print(JOU_COLOR_RED);
                    }
                    jou.print("%02hhx", *pHEX);
                    jou.print(JOU_COLOR_RESET);
#else
                    jou.print("%02hhx", *pHEX);
#endif
                }
                itemp++, pHEX++;
            }
            jou.putc(' ');
        }

        jou.putc(' ');
        itemp = i;
        for (size_t j = 0; j < JCONFIG_HEXDUMP_BYTES_IN_LINE; j++) {
            if (itemp < len) {
                if (isjdump(*pASCII)) {
#if JCONFIG_COLORS == 1
                    jou.print(JOU_COLOR_YELLOW);
                    jou.putc(*pASCII);
                    jou.print(JOU_COLOR_RESET);
#else
                    jou.putc(*pASCII);
#endif
                } else {
#if JCONFIG_COLORS == 1
                if(isjnoascii(*pASCII)) {
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
            itemp++, pASCII++;
        }
        
        if (i >= len) return;
        jou.putc('\n');
        i = itemp;
#if JCONFIG_DUMP_DIRECTION_TOP == 1
        line += JCONFIG_HEXDUMP_BYTES_IN_LINE;
#else
        line -= JCONFIG_HEXDUMP_BYTES_IN_LINE;
#endif
    }
}
#else

#endif