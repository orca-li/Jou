#if !defined(JOUSUP_H)
#define JOUSUP_H

#include <stdarg.h>

#define isjoudump(c) (isgraph(c) || c == ' ')

int sprintj(char *buf, const char *fmt, va_list *args);
int printj(const char *fmt, va_list *args);

#endif /* JOUSUP_H */