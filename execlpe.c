/* See LICENSE file for copyright and license details. */
#include "common.h"
#ifndef TEST


int
libsimple_execlpe(const char *file, ... /* argv, NULL, char *const envp[] */)
{
	int ret;
	va_list args;
	va_start(args, file);
	ret = libsimple_vexeclpe(file, args);
	va_end(args);
	return ret;
}


#else
#include "test.h"

int
main(void)
{
        return 0;
}

#endif
