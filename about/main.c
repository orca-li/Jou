#include <jou.h>

#include <string.h>

int main(void) 
{
    jou.err("hello world!");
    jou.wrn("h(%02x) e(%02x), l(%02x), l(%02x), o(%02x)", 'h', 'e', 'l', 'l', 'o');
    jou.inf("info(%d)", 692);
    jou.dbg("w");
    jou.put('O');
    jou.print("rcali\n");

    char arr[] = "\0hello world, hi jou, hi orcali and hi hexdump!!";
    jou.hex(arr, 64);
    

    return 0;
}