#include <jou.h>

int main(void) 
{
    /* CACHE */
    char arr[128];
    char tstr[128];
    int tint;
    char tchar;
    int thex;
    char temp;

    /* API */
    jou.err("hello world!");
    jou.wrn("h(%02x) e(%02x), l(%02x), l(%02x), o(%02x)", 'h', 'e', 'l', 'l', 'o');
    jou.inf("info(%d)", 692);
    jou.dbg("w");
    jou.putc('O');
    jou.print("rcali\n");

    jou.hex(arr, 128);
    
    jou.dbg("Enter string: %%d %%c %%x %%s");
    jou.scan("%d %c %x %s", &tint, &tchar, &thex, tstr);
    jou.wrn("tint = %d tchar = %c(%02x), thex = %d(%x)", 
        tint, tchar, tchar, thex, thex);
    jou.err("tstr = %s", tstr);

    temp = jou.getc();
    jou.inf("echo(%c)", temp);

    jou.inf("sizeof(jou): %d", sizeof(jou));

    return 0;
}