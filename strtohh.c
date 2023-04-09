/* See LICENSE file for copyright and license details. */
#include "common.h"
#ifndef TEST


signed char
libsimple_strtohh(const char *restrict nptr, char **restrict end, int base)
{
	signed long int r = strtol(nptr, end, base);
	if (r < SCHAR_MIN) {
		r = SCHAR_MIN;
		errno = ERANGE;
	} else if (r > SCHAR_MAX) {
		r = SCHAR_MAX;
		errno = ERANGE;
	}
	return (signed char)r;
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
	sprintf(str, "0x%x", (unsigned int)SCHAR_MAX);
	errno = 0;
	assert(strtohh(str, NULL, 0) == SCHAR_MAX && !errno);
	assert(strtohh(str, NULL, 16) == SCHAR_MAX && !errno);
	assert(strtohh(&str[2], NULL, 16) == SCHAR_MAX && !errno);
	assert(strtohh(str, NULL, 10) == 0 && !errno);
	assert(strtohh(str, &e, 0) == SCHAR_MAX && !*e && !errno);
	assert(strtohh(str, &e, 10) == 0 && *e == 'x' && !errno);
	sprintf(str, "0x%x ", (unsigned int)SCHAR_MAX);
	assert(strtohh(str, &e, 16) == SCHAR_MAX && *e == ' ' && !errno);
	sprintf(str, "-%i", SCHAR_MAX);
	assert(strtohh(&str[1], &e, 10) == SCHAR_MAX && !*e && !errno);
	assert(strtohh(str, &e, 10) == -SCHAR_MAX && !*e && !errno);
	sprintf(str, "%i", SCHAR_MIN);
	assert(strtohh(str, &e, 10) == SCHAR_MIN && !*e && !errno);
	assert(strtohh("12", &e, 10) == 12 && !*e && !errno);
	assert(strtohh("12", &e, 8) == 012 && !*e && !errno);
	assert(strtohh("012", &e, 0) == 012 && !*e && !errno);
	sprintf(str, "%i", SCHAR_MAX);
	add_one(str);
	assert(strtohh(str, &e, 10) == SCHAR_MAX && !*e && errno == ERANGE);
	errno = 0;
	sprintf(str, "%i", SCHAR_MIN);
	add_one(str);
	assert(strtohh(str, &e, 10) == SCHAR_MIN && !*e && errno == ERANGE);
	errno = 0;
	assert(!strtohh("1", &e, -10000) && errno == EINVAL);
	errno = 0;
	return 0;
}

#endif
