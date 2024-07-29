/**
 * @copyright MIT License (C) 2024 Orcali
 * @version v0.1.1
 */
#include <jou.h>
#include "include/jouSUP.h"

int main(void) 
{
    /* CACHE */
    char arr[133];
    strmrg(arr, 4, "hello", " world!", " O", "rcali :)");
    jou.hex(arr, 213);
    jou.inf("sizeof(jou): %d", sizeof(jou));
    
    return 0;
}