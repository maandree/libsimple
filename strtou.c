/* See LICENSE file for copyright and license details. */
#include "common.h"
#ifndef TEST


unsigned int
libsimple_strtou(const char *restrict nptr, char **restrict end, int base)
{
	unsigned long int r = strtoul(nptr, end, base);
	if (r > UINT_MAX) {
		r = UINT_MAX;
		errno = ERANGE;
	}
	return (unsigned int)r;
}


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
	sprintf(str, "0x%x", UINT_MAX);
	errno = 0;
	assert(strtou(str, NULL, 0) == UINT_MAX && !errno);
	assert(strtou(str, NULL, 16) == UINT_MAX && !errno);
	assert(strtou(&str[2], NULL, 16) == UINT_MAX && !errno);
	assert(strtou(str, NULL, 10) == 0 && !errno);
	assert(strtou(str, &e, 0) == UINT_MAX && !*e && !errno);
	assert(strtou(str, &e, 10) == 0 && *e == 'x' && !errno);
	sprintf(str, "0x%x ", UINT_MAX);
	assert(strtou(str, &e, 16) == UINT_MAX && *e == ' ' && !errno);
	sprintf(str, "%u", UINT_MAX);
	assert(strtou(str, &e, 10) == UINT_MAX && !*e && !errno);
	assert(strtou("1234", &e, 10) == 1234 && !*e && !errno);
	assert(strtou("1234", &e, 8) == 01234 && !*e && !errno);
	assert(strtou("01234", &e, 0) == 01234 && !*e && !errno);
	sprintf(str, "%u", UINT_MAX);
	add_one(str);
	assert(strtou(str, &e, 10) == UINT_MAX && !*e && errno == ERANGE);
	errno = 0;
	assert(!strtou("1", &e, -10000) && errno == EINVAL);
	errno = 0;
	return 0;
}

#endif
