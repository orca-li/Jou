#if !defined(JOUFMT_H)
#define JOUFMT_H

#include <stdarg.h>
#include <stddef.h>

#define JOU_LEVEL_ERROR "Error"
#define JOU_LEVEL_WARNING "Warning"
#define JOU_LEVEL_DEBUG "Debug"
#define JOU_LEVEL_INFO "Info"

#define JOU_COLOR_RED "\e[0;31m"
#define JOU_COLOR_GREEN "\e[0;32m"
#define JOU_COLOR_YELLOW "\e[0;33m"
#define JOU_COLOR_BLUE "\e[0;34m"
#define JOU_COLOR_RESET "\e[0;0m"

void __PRIVATEjouHexDump(char *buf, size_t len, va_list *args);

#endif /* JOUFMT_H */