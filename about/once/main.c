/**
 * @copyright MIT License (c) 2024 Orcali
 * @version 0.2
 */
#include <jou.h>
#include "include/jouSUP.h"

int main(void) 
{
    /* CACHE */
    char arr[133];
    strmrg(arr, 4, "hello", " world!", " O", "rcali :)");
    jou.hex(arr, 39);
    jou.inf("sizeof(jou): %d", sizeof(jou));
    jou.hook("new function");
    jou.tag("main.c", "hello");
    jou.bin(arr, 51);
    
    return 0;
}