/* See LICENSE file for copyright and license details. */
#include "common.h"
#ifndef TEST


signed short int
libsimple_strtoh(const char *restrict nptr, char **restrict end, int base)
{
	signed long int r = strtol(nptr, end, base);
	if (r < SHRT_MIN) {
		r = SHRT_MIN;
		errno = ERANGE;
	} else if (r > SHRT_MAX) {
		r = SHRT_MAX;
		errno = ERANGE;
	}
	return (signed short int)r;
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
	sprintf(str, "0x%x", (unsigned int)SHRT_MAX);
	errno = 0;
	assert(strtoh(str, NULL, 0) == SHRT_MAX && !errno);
	assert(strtoh(str, NULL, 16) == SHRT_MAX && !errno);
	assert(strtoh(&str[2], NULL, 16) == SHRT_MAX && !errno);
	assert(strtoh(str, NULL, 10) == 0 && !errno);
	assert(strtoh(str, &e, 0) == SHRT_MAX && !*e && !errno);
	assert(strtoh(str, &e, 10) == 0 && *e == 'x' && !errno);
	sprintf(str, "0x%x ", (unsigned int)SHRT_MAX);
	assert(strtoh(str, &e, 16) == SHRT_MAX && *e == ' ' && !errno);
	sprintf(str, "-%i", SHRT_MAX);
	assert(strtoh(&str[1], &e, 10) == SHRT_MAX && !*e && !errno);
	assert(strtoh(str, &e, 10) == -SHRT_MAX && !*e && !errno);
	sprintf(str, "%i", SHRT_MIN);
	assert(strtoh(str, &e, 10) == SHRT_MIN && !*e && !errno);
	assert(strtoh("1234", &e, 10) == 1234 && !*e && !errno);
	assert(strtoh("1234", &e, 8) == 01234 && !*e && !errno);
	assert(strtoh("01234", &e, 0) == 01234 && !*e && !errno);
	sprintf(str, "%i", SHRT_MAX);
	add_one(str);
	assert(strtoh(str, &e, 10) == SHRT_MAX && !*e && errno == ERANGE);
	errno = 0;
	sprintf(str, "%i", SHRT_MIN);
	add_one(str);
	assert(strtoh(str, &e, 10) == SHRT_MIN && !*e && errno == ERANGE);
	errno = 0;
	assert(!strtoh("1", &e, -10000) && errno == EINVAL);
	errno = 0;
	return 0;
}

#endif
