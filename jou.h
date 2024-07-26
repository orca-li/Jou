#if !defined(JOU_H)
#define JOU_H

#include "jouCONFIG.h"

#include <stddef.h>

typedef void (*method)(char *fmt, ...);

struct JOU_CONFIG {

};

struct JOU_BODY {
    struct {
        const method err;
        const method wrn;
        const method dbg;
        const method inf;
        const method print;
        void (*put)(char);
        void (*xxd)(char*, size_t len);
    };
    struct JOU_CONFIG config;
};

extern struct JOU_BODY jou;

#define JOU_LEVEL_ERROR "Error"
#define JOU_LEVEL_WARNING "Warning"
#define JOU_LEVEL_DEBUG "Debug"
#define JOU_LEVEL_INFO "Info"

#define JOU_COLOR_RED "\e[0;31m"
#define JOU_COLOR_GREEN "\e[0;32m"
#define JOU_COLOR_YELLOW "\e[0;33m"
#define JOU_COLOR_BLUE "\e[0;34m"
#define JOU_COLOR_RESET "\e[0;0m"

#endif /* JOU_H */