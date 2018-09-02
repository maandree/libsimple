/* See LICENSE file for copyright and license details. */
#include "libsimple.h"
#ifndef TEST


char *
libsimple_strndup(const char *s, size_t n)
{
	char *ret;
	size_t m = strlen(s);
	n = MIN(n, m);
	if (n == SIZE_MAX) {
		errno = ENOMEM;
		return NULL;
	}
	if (!(ret = aligned_alloc(1, n + 1)))
		return NULL;
	memcpy(ret, s, n);
	ret[n] = '\0';
	return ret;
}


#else
#include "test.h"

int
main(void)
{
	struct allocinfo *info;
	const char *s = "test";
	void *p;

	p = libsimple_strndup(s, 5);
	assert(p && p != s);
	assert(!strcmpnul(p, "test"));
	memset(p, 0, 5);
	assert(!strcmpnul(s, "test"));
	if (have_custom_malloc()) {
		assert((info = get_allocinfo(p)));
		assert(info->alignment == 1);
	}
	free(p);

	p = libsimple_strndup(s, 3);
	assert(p && p != s);
	assert(!strcmpnul(p, "tes"));
	memset(p, 0, 4);
	assert(!strcmpnul(s, "test"));
	if (have_custom_malloc()) {
		assert((info = get_allocinfo(p)));
		assert(info->alignment == 1);
	}
	free(p);

	p = libsimple_strndup(s, 0);
	assert(p && p != s);
	assert(!strcmpnul(p, ""));
	memset(p, 0, 1);
	assert(!strcmpnul(s, "test"));
	if (have_custom_malloc()) {
		assert((info = get_allocinfo(p)));
		assert(info->alignment == 1);
	}
	free(p);

	return 0;
}

#endif
