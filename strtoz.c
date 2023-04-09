/* See LICENSE file for copyright and license details. */
#include "common.h"
#ifndef TEST


extern inline ssize_t libsimple_strtoz(const char *restrict, char **restrict, int);


#else
#include "test.h"

#ifndef SSIZE_MIN
#define SSIZE_MIN (-SSIZE_MAX - (-LONG_MAX != LONG_MIN))
#endif

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
	sprintf(str, "0x%zx", SSIZE_MAX);
	errno = 0;
	assert(strtoz(str, NULL, 0) == SSIZE_MAX && !errno);
	assert(strtoz(str, NULL, 16) == SSIZE_MAX && !errno);
	assert(strtoz(&str[2], NULL, 16) == SSIZE_MAX && !errno);
	assert(strtoz(str, NULL, 10) == 0 && !errno);
	assert(strtoz(str, &e, 0) == SSIZE_MAX && !*e && !errno);
	assert(strtoz(str, &e, 10) == 0 && *e == 'x' && !errno);
	sprintf(str, "0x%zx ", SSIZE_MAX);
	assert(strtoz(str, &e, 16) == SSIZE_MAX && *e == ' ' && !errno);
	sprintf(str, "-%zi", SSIZE_MAX);
	assert(strtoz(&str[1], &e, 10) == SSIZE_MAX && !*e && !errno);
	assert(strtoz(str, &e, 10) == -SSIZE_MAX && !*e && !errno);
	sprintf(str, "%zi", SSIZE_MIN);
	assert(strtoz(str, &e, 10) == SSIZE_MIN && !*e && !errno);
	assert(strtoz("1234", &e, 10) == 1234 && !*e && !errno);
	assert(strtoz("1234", &e, 8) == 01234 && !*e && !errno);
	assert(strtoz("01234", &e, 0) == 01234 && !*e && !errno);
	sprintf(str, "%zi", SSIZE_MAX);
	add_one(str);
	assert(strtoz(str, &e, 10) == SSIZE_MAX && !*e && errno == ERANGE);
	errno = 0;
	sprintf(str, "%zi", SSIZE_MIN);
	add_one(str);
	assert(strtoz(str, &e, 10) == SSIZE_MIN && !*e && errno == ERANGE);
	errno = 0;
	assert(!strtoz("1", &e, -10000) && errno == EINVAL);
	errno = 0;
	return 0;
}

#endif
