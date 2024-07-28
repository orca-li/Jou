#include <stdio.h>
#include "include/jouTEMP.h"

#if 0
void strmrg(char *buf, char *add, )
{

}
#endif

int sprintj(char *buf, const char *fmt, va_list *args)
{
	return vsprintf(buf, fmt, *args);
}

int printj(const char *fmt, va_list *args)
{
	char printf_buf[JCONFIG_PRINTJ_BUF_SIZE];
	int printed;

	printed = vsprintf(printf_buf, fmt, *args);

    JCONFIG_TUNNEL_PRINT(printf_buf);

	return printed;
}