#include "jouCONFIG.h"
#include "include/jouFMT.h"

#include <stdio.h>
#include <stdint.h>
#include <ctype.h>
#include <wchar.h>

#define isjouhex(c) (isgraph(c) || c == ' ')

static void printHexLine();


#if defined(JCONFIG_COLORS)
void __PRIVATEjouHexDump(char *buf, size_t len, va_list *args)
{
    size_t line = 0;
    size_t i = 0;
    size_t itemp;

    char *pHEX, *pASCII;
    pHEX = pASCII = buf;

    while (i < len) {
        printf(JOU_COLOR_YELLOW);
#if JCONFIG_WIDE_DUMP == 1
        printf("%08X", line);
#else
        printf("%04X", line);
#endif
        printf(JOU_COLOR_RESET);
        printf(": ");

        itemp = i;
        printf(JOU_COLOR_RESET);
        for (size_t j = 0; j < JCONFIG_HEXDUMP_BYTES_IN_LINE / 2; j++) {
            for (size_t k = 0; k < JCONFIG_HEXDUMP_BYTES_PER_SPACE; k++) {
                if (itemp >= len) {
                    printf("  ");
                } else {
                    if (isjouhex(*pHEX)) {
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

        itemp = i;
        for (size_t j = 0; j < JCONFIG_HEXDUMP_BYTES_IN_LINE; j++) {
            if (itemp < len) {
                if (isjouhex(*pASCII)) {
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
        line += JCONFIG_HEXDUMP_BYTES_IN_LINE;
    }
}
#else

#endif