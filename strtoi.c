/* See LICENSE file for copyright and license details. */
#include "common.h"
#ifndef TEST


signed int
libsimple_strtoi(const char *restrict nptr, char **restrict end, int base)
{
	signed long int r = strtol(nptr, end, base);
	if (r < INT_MIN) {
		r = INT_MIN;
		errno = ERANGE;
	} else if (r > INT_MAX) {
		r = INT_MAX;
		errno = ERANGE;
	}
	return (signed int)r;
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
	sprintf(str, "0x%x", INT_MAX);
	errno = 0;
	assert(strtoi(str, NULL, 0) == INT_MAX && !errno);
	assert(strtoi(str, NULL, 16) == INT_MAX && !errno);
	assert(strtoi(&str[2], NULL, 16) == INT_MAX && !errno);
	assert(strtoi(str, NULL, 10) == 0 && !errno);
	assert(strtoi(str, &e, 0) == INT_MAX && !*e && !errno);
	assert(strtoi(str, &e, 10) == 0 && *e == 'x' && !errno);
	sprintf(str, "0x%x ", INT_MAX);
	assert(strtoi(str, &e, 16) == INT_MAX && *e == ' ' && !errno);
	sprintf(str, "-%i", INT_MAX);
	assert(strtoi(&str[1], &e, 10) == INT_MAX && !*e && !errno);
	assert(strtoi(str, &e, 10) == -INT_MAX && !*e && !errno);
	sprintf(str, "%i", INT_MIN);
	assert(strtoi(str, &e, 10) == INT_MIN && !*e && !errno);
	assert(strtoi("1234", &e, 10) == 1234 && !*e && !errno);
	assert(strtoi("1234", &e, 8) == 01234 && !*e && !errno);
	assert(strtoi("01234", &e, 0) == 01234 && !*e && !errno);
	sprintf(str, "%i", INT_MAX);
	add_one(str);
	assert(strtoi(str, &e, 10) == INT_MAX && !*e && errno == ERANGE);
	errno = 0;
	sprintf(str, "%i", INT_MIN);
	add_one(str);
	assert(strtoi(str, &e, 10) == INT_MIN && !*e && errno == ERANGE);
	errno = 0;
	assert(!strtoi("1", &e, -10000) && errno == EINVAL);
	errno = 0;
	return 0;
}

#endif
