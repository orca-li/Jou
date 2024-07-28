#include "jouCONFIG.h"
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
        printf(JOU_COLOR_YELLOW);
        printf("%08x", line);
        printf(JOU_COLOR_RESET);
        printf(":  ");

        itemp = i;
        printf(JOU_COLOR_RESET);
        for (size_t j = 0; j < JCONFIG_HEXDUMP_BYTES_IN_LINE / 2; j++) {
            for (size_t k = 0; k < JCONFIG_HEXDUMP_BYTES_PER_SPACE; k++) {
                if (itemp >= len) {
                    printf("  ");
                } else {
                    if (isjoudump(*pHEX)) {
                        printf(JOU_COLOR_YELLOW);
                    }
                    char temp = *pHEX;
                    printf("%02hhx", temp);
                    printf(JOU_COLOR_RESET);
                }
                itemp++, pHEX++;
            }
            putchar(' ');
        }

        putchar(' ');
        itemp = i;
        for (size_t j = 0; j < JCONFIG_HEXDUMP_BYTES_IN_LINE; j++) {
            if (itemp < len) {
                if (isjoudump(*pASCII)) {
                    printf(JOU_COLOR_YELLOW);
                    putchar(*pASCII);
                    printf(JOU_COLOR_RESET);
                } else {
                    putchar('.');
                }
            }
            itemp++, pASCII++;
        }
        

        if (i >= len) return;
        putchar('\n');
        i = itemp;
#if JCONFIG_ADDRESS_COLUMN == 1
        line -= JCONFIG_HEXDUMP_BYTES_IN_LINE;
#else
        line += JCONFIG_HEXDUMP_BYTES_IN_LINE;
#endif
    }
}
#else

#endif