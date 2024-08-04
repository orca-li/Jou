/**
 * @copyright MIT License, 2024 (c) Orcali
 * @version 0.3
 */
#include <jou.h>
#include "include/jouSUP.h"

int main(void) 
{
    /* CACHE */
    
    char arr[128] = "\"What society does to its children, its children will do to society.\" - Marcus Tullius Cicero";
    char arr2[128] = "\"A man should be handsome in everything: in his face, in his clothes, in his soul, and in his thoughts.\" - Anton Chekhov";

#if jconfigLITE_VERSION == 0

    jou.hex(arr, 51);
    jou.inf("sizeof(jou): %d", sizeof(jou));
    jou.hook("new function");
    jou.bin(arr2, 51);
    jou.tag("main.c", "hello");
    jou.cmp(arr, arr2, 128);

#else
    JOUX(arr, 39);
    JOUI("sizeof(jou): %d", 0);
    JOUH("new function");
    JOUT("main.c", "hello");
    JOUB(arr, 51);

#endif
    
    return 0;
}