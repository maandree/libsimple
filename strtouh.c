/* See LICENSE file for copyright and license details. */
#include "common.h"
#ifndef TEST


unsigned short int
libsimple_strtouh(const char *restrict nptr, char **restrict end, int base)
{
	unsigned long int r = strtoul(nptr, end, base);
	if (r > USHRT_MAX) {
		r = USHRT_MAX;
		errno = ERANGE;
	}
	return (unsigned short int)r;
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
	sprintf(str, "0x%x", (unsigned int)USHRT_MAX);
	errno = 0;
	assert(strtouh(str, NULL, 0) == USHRT_MAX && !errno);
	assert(strtouh(str, NULL, 16) == USHRT_MAX && !errno);
	assert(strtouh(&str[2], NULL, 16) == USHRT_MAX && !errno);
	assert(strtouh(str, NULL, 10) == 0 && !errno);
	assert(strtouh(str, &e, 0) == USHRT_MAX && !*e && !errno);
	assert(strtouh(str, &e, 10) == 0 && *e == 'x' && !errno);
	sprintf(str, "0x%x ", (unsigned int)USHRT_MAX);
	assert(strtouh(str, &e, 16) == USHRT_MAX && *e == ' ' && !errno);
	sprintf(str, "%u", (unsigned int)USHRT_MAX);
	assert(strtouh(str, &e, 10) == USHRT_MAX && !*e && !errno);
	assert(strtouh("1234", &e, 10) == 1234 && !*e && !errno);
	assert(strtouh("1234", &e, 8) == 01234 && !*e && !errno);
	assert(strtouh("01234", &e, 0) == 01234 && !*e && !errno);
	sprintf(str, "%u", (unsigned int)USHRT_MAX);
	add_one(str);
	assert(strtouh(str, &e, 10) == USHRT_MAX && !*e && errno == ERANGE);
	errno = 0;
	assert(!strtouh("1", &e, -10000) && errno == EINVAL);
	errno = 0;
	return 0;
}

#endif
