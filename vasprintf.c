/* See LICENSE file for copyright and license details. */
#include "libsimple.h"


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
