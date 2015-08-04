#include "system.h"
#include <stdarg.h>
#include <time.h>
#include <stdlib.h>
#include <memory.h>
#include <stdio.h>

#ifdef __cplusplus
extern "C" {
#endif

/*
 * DEBUGGING & TESTING
 */

void dbg_msg(const char *sys, const char *fmt, ...)
{
	va_list args;
	char str[1024*4];
	char *msg;
	int len;

	str_format(str, sizeof(str), "[%08x][%s]: ", (int)time(0), sys);
	len = strlen(str);
	msg = (char *)str + len;

	va_start(args, fmt);
#if defined(CONF_FAMILY_WINDOWS)
	_vsnprintf(msg, sizeof(str)-len, fmt, args);
#else
	vsnprintf(msg, sizeof(str)-len, fmt, args);
#endif
	va_end(args);

	printf("%s\n", msg);
}

/*
 * MEMORY
 */

void mem_zero(void *block, unsigned size)
{
	memset(block, 0, size);
}

void* mem_alloc(unsigned size, unsigned amount)
{
	return malloc(size*amount);
}

/*
 * STRINGS
 */

void str_format(char *buffer, int buffer_size, const char *format, ...)
{
#if defined(CONF_FAMILY_WINDOWS)
	va_list ap;
	va_start(ap, format);
	memset(buffer, 0, buffer_size);
	_vsnprintf(buffer, buffer_size, format, ap);
	va_end(ap);
#else
	va_list ap;
	va_start(ap, format);
	memset(buffer, 0, buffer_size);
	vsnprintf(buffer, buffer_size, format, ap);
	va_end(ap);
#endif

	buffer[buffer_size-1] = 0; /* assure null termination */
}


#ifdef __cplusplus
}
#endif
