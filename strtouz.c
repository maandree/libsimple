/* See LICENSE file for copyright and license details. */
#include "common.h"
#ifndef TEST


extern inline size_t libsimple_strtouz(const char *restrict, char **restrict, int);


#else
#include "test.h"

static void
add_one(char *buf)
{
	char *p = strchr(buf, '\0');
	while (*--p == '9')
		*p = '0';
	*p += 1;
}

int
main(void)
{
	char str[128];
	char *e;
	sprintf(str, "0x%zx", SIZE_MAX);
	errno = 0;
	assert(strtouz(str, NULL, 0) == SIZE_MAX && !errno);
	assert(strtouz(str, NULL, 16) == SIZE_MAX && !errno);
	assert(strtouz(&str[2], NULL, 16) == SIZE_MAX && !errno);
	assert(strtouz(str, NULL, 10) == 0 && !errno);
	assert(strtouz(str, &e, 0) == SIZE_MAX && !*e && !errno);
	assert(strtouz(str, &e, 10) == 0 && *e == 'x' && !errno);
	sprintf(str, "0x%zx ", SIZE_MAX);
	assert(strtouz(str, &e, 16) == SIZE_MAX && *e == ' ' && !errno);
	sprintf(str, "%zu", SIZE_MAX);
	assert(strtouz(str, &e, 10) == SIZE_MAX && !*e && !errno);
	assert(strtouz("1234", &e, 10) == 1234 && !*e && !errno);
	assert(strtouz("1234", &e, 8) == 01234 && !*e && !errno);
	assert(strtouz("01234", &e, 0) == 01234 && !*e && !errno);
	sprintf(str, "%zu", SIZE_MAX);
	add_one(str);
	assert(strtouz(str, &e, 10) == SIZE_MAX && !*e && errno == ERANGE);
	errno = 0;
	assert(!strtouz("1", &e, -10000) && errno == EINVAL);
	errno = 0;
	return 0;
}

#endif
