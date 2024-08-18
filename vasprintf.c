/* See LICENSE file for copyright and license details. */
#include "common.h"
#ifndef TEST

#if defined(__clang__)
# pragma clang diagnostic ignored "-Wformat-nonliteral"
#endif


int
libsimple_vasprintf(char **strp, const char *fmt, va_list ap)
{
	FILE *fp;
	size_t siz = 0;
	int ret;
	*strp = NULL;
	fp = open_memstream(strp, &siz);
	if (!fp)
		goto fail;
	ret = vfprintf(fp, fmt, ap);
	if (ret < 0)
		goto fail;
	if (fputc(0, fp))
		goto fail;
	fclose(fp);
	return ret;
fail:
	free(*strp);
	*strp = NULL;
	return -1;
}


#else
#include "test.h"

int
main(void)
{
	return 0; /* Tested via libsimple_asprintf */
}

#endif
