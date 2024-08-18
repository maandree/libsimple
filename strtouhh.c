/* See LICENSE file for copyright and license details. */
#include "common.h"
#ifndef TEST


unsigned char
libsimple_strtouhh(const char *restrict nptr, char **restrict end, int base)
{
	unsigned long int r = strtoul(nptr, end, base);
	if (r > UCHAR_MAX) {
		r = UCHAR_MAX;
		errno = ERANGE;
	}
	return (unsigned char)r;
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
	sprintf(str, "0x%x", (unsigned int)UCHAR_MAX);
	errno = 0;
	assert(strtouhh(str, NULL, 0) == UCHAR_MAX && !errno);
	assert(strtouhh(str, NULL, 16) == UCHAR_MAX && !errno);
	assert(strtouhh(&str[2], NULL, 16) == UCHAR_MAX && !errno);
	assert(strtouhh(str, NULL, 10) == 0 && !errno);
	assert(strtouhh(str, &e, 0) == UCHAR_MAX && !*e && !errno);
	assert(strtouhh(str, &e, 10) == 0 && *e == 'x' && !errno);
	sprintf(str, "0x%x ", (unsigned int)UCHAR_MAX);
	assert(strtouhh(str, &e, 16) == UCHAR_MAX && *e == ' ' && !errno);
	sprintf(str, "%u", (unsigned int)UCHAR_MAX);
	assert(strtouhh(str, &e, 10) == UCHAR_MAX && !*e && !errno);
	assert(strtouhh("12", &e, 10) == 12 && !*e && !errno);
	assert(strtouhh("12", &e, 8) == 012 && !*e && !errno);
	assert(strtouhh("012", &e, 0) == 012 && !*e && !errno);
	sprintf(str, "%u", (unsigned int)UCHAR_MAX);
	add_one(str);
	assert(strtouhh(str, &e, 10) == UCHAR_MAX && !*e && errno == ERANGE);
	errno = 0;
	assert(!strtouhh("1", &e, -10000) && errno == EINVAL);
	errno = 0;
	return 0;
}

#endif
