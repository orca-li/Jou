/**
 * @copyright MIT License (C) 2024 Orcali
 * @version v0.1.1
 */
#if !defined(JOUSUP_H)
#define JOUSUP_H

#include <stdarg.h>

#define jsizeof(arr) (sizeof(arr) / sizeof(*arr))
#define isjnoascii(c) ((unsigned char)c >= 128)
#define isjdump(c) (isgraph(c) || c == ' ')

void strmrg(char *buf, unsigned char number, ...);
int sprintj(char *buf, const char *fmt, va_list *args);
int printj(const char *fmt, va_list *args);

#endif /* JOUSUP_H */