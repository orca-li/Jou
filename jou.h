#if !defined(JOU_H)
#define JOU_H

typedef void (*method)(char *fmt, ...);

struct JOU_BODY {
    struct {
        const method err;
        const method wrn;
        const method dbg;
        const method inf;
    };
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