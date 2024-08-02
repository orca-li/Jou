/**
 * @copyright MIT License, 2024 (c) Orcali
 * @version 0.2.2
 */
#include <jou.h>
#include "include/jouSUP.h"

int main(void) 
{
    /* CACHE */
    char arr[133];
    strmrg(arr, 4, "hello", " world!", " O", "rcali :)");

#if jconfigLITE_VERSION == 0

    jou.hex(arr, 39);
    jou.inf("sizeof(jou): %d", sizeof(jou));
    jou.hook("new function");
    jou.tag("main.c", "hello");
    jou.bin(arr, 51);

#else
    JOUX(arr, 39);
    JOUI("sizeof(jou): %d", 0);
    JOUH("new function");
    JOUT("main.c", "hello");
    JOUB(arr, 51);

#endif
    
    return 0;
}