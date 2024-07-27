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
typedef void (*vfv_jt)(void);
typedef void (*vfc_jt)(char);
typedef void (*vfsa_jt)(char *, ...);
typedef void (*vfsla_jt)(char *, size_t, ...);

struct JOU_CONFIG {
    const vfv_jt reset;
};

typedef struct JOU_JT {
    struct {
        /* stdio */
        const vfsa_jt print;
        const vfc_jt put;

        /* logs */
        const vfsa_jt err;
        const vfsa_jt wrn;
        const vfsa_jt dbg;
        const vfsa_jt inf;
        
        /* dumps */
        const vfsla_jt hex;
        const vfsla_jt bin;
    };
    struct JOU_CONFIG config;
} jou_jt;

extern jou_jt jou;



#endif /* JOU_H */