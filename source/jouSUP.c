/**
 * @copyright MIT License (C) 2024 Orcali
 * @version v0.1.1
 */
#include <stdio.h>
#include <string.h>
#include "include/jouTEMP.h"

void strmrg(char *buf, unsigned char number, ...)
{
	va_list args;
	va_start(args, number);

	unsigned char c;
	char *ptemp;
	while(c++ < number) {
		ptemp = va_arg(args, char*);
		strcpy(buf, ptemp);
		buf += strlen(ptemp);
	}
	va_end(args);
	*buf = '\0';
}

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