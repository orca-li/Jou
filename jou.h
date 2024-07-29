/**
 * @copyright MIT License (C) 2024 Orcali
 * @version v0.1.1
 */
#if !defined(JOU_H)
#define JOU_H

#include <stddef.h>
#include "include/jouERR.h"

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
typedef void (*vfc_jt)(char);
typedef void (*vfsa_jt)(char*, ...);
typedef void (*vfsl_jt)(char*, size_t);
typedef int (*ifv_jt)(void);

typedef ifv_jt getc_jt;
typedef vfc_jt putc_jt;
typedef vfsa_jt printf_jt;
typedef vfsl_jt dump_jt;

typedef struct JOU_JT {
    struct { 
        /* stdio */
        const printf_jt print;
        const printf_jt scan;
        const putc_jt putc;
        const getc_jt getc;

        /* logs */
        const printf_jt err;
        const printf_jt wrn;
        const printf_jt dbg;
        const printf_jt inf;
        
        /* dumps */
        const dump_jt hex;
        const dump_jt bin;
    };
} jou_jt;

extern jou_jt chj0;

#endif /* JOU_H */