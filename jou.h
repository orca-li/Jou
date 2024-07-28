#if !defined(JOU_H)
#define JOU_H

#include <stddef.h>

#include "include/jouERR.h"

/* Preprocessor directives JOU_CONFIG */
#define JPD_HEX_ADDRESS (1 << 0)

/** @typedef for functions
 * 
 * @details
 * j%f%%_t - jou type
 * %1 - return type
 * %2 - type ((f)unction, (p)ointer)
 * %3-%n - params
 * (a)rgs, (c)har, (s)tring, (l)ong {unsigned long, size_t}
 * 
 */
typedef void (*vfv_jt)(void);
typedef void (*vfc_jt)(char);
typedef void (*vfsa_jt)(char*, ...);
typedef void (*vfsl_jt)(char*, size_t);
typedef void (*vfssa_jt)(char*, char*, ...);
typedef int (*ifv_jt)(void);
typedef unsigned char reg8_jt;

struct JOU_CONFIG {
    const vfv_jt reset;
};

typedef struct JOU_JT {
    struct { 
        /* stdio */
        const vfsa_jt print;
        const vfc_jt putc;
        const vfsa_jt scan;
        const ifv_jt getc;

        /* logs */
        const vfsa_jt err;
        const vfsa_jt wrn;
        const vfsa_jt dbg;
        const vfsa_jt inf;
        
        /* dumps */
        const vfsl_jt hex;
        const vfsl_jt bin;
    };

    /* tools */
    struct {
        const vfssa_jt merge;
    };
    struct JOU_CONFIG config;
} jou_jt;

extern jou_jt chj0;

#endif /* JOU_H */