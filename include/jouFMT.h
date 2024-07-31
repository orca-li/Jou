/**
 * @copyright MIT License (C) 2024 Orcali
 * @version 0.2
 */
#if !defined(JOUFMT_H)
#define JOUFMT_H

#include <stddef.h>

#define JOU_LEVEL_ERROR "Error"
#define JOU_LEVEL_WARNING "Warning"
#define JOU_LEVEL_DEBUG "Debug"
#define JOU_LEVEL_INFO "Info"
#define JOU_LEVEL_HOOK "Hook"

#define JOU_COLOR_RED "\e[0;31m"
#define JOU_COLOR_GREEN "\e[0;32m"
#define JOU_COLOR_YELLOW "\e[0;33m"
#define JOU_COLOR_BLUE "\e[0;34m"
#define JOU_COLOR_RESET "\e[0;0m"

#define jfmtDUMP_BIN 0
#define jfmtDUMP_HEX 1

void __PRIVATEjouDump(const char type, const char *buf, const size_t len);

#endif /* JOUFMT_H */