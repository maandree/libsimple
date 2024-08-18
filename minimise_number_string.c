/* See LICENSE file for copyright and license details. */
#include "common.h"
#ifndef TEST


char *
libsimple_minimise_number_string(char *s)
{
	char *p, *ret = s;
	size_t n;

	if (*s == '+')
		memmove(s, &s[1], strlen(s));

	p = strchr(s, '.');
	if (p) {
		p = strchr(p, '\0');
		while (p[-1] == '0')
			*--p = '\0';
		if (p[-1] == '.') {
			if (s[0] == '.') {
				s[0] = '0';
				return ret;
			} else if (s[0] == '-' && s[1] == '.') {
				s[1] = '0';
				return ret;
			}
			*--p = '\0';
		}
	}

	if (*s == '-')
		s = &s[1];

	for (p = s; *p == '0'; p++);
	n = (size_t)(p - s);
	if (!*p || *p == '.')
		n -= !!n;
	memmove(s, &s[n], strlen(&s[n]) + 1);

	return ret;
}


#else
#include "test.h"

int
main(void)
{
	char buf[1000];

	/* Some aspects are tested in libsimple.c */

	assert(!strcmp(libsimple_minimise_number_string(strcpy(buf, "00100.00000")), "100"));
	assert(!strcmp(libsimple_minimise_number_string(strcpy(buf, "00100.1")), "100.1"));
	assert(!strcmp(libsimple_minimise_number_string(strcpy(buf, "00100.000001")), "100.000001"));
	assert(!strcmp(libsimple_minimise_number_string(strcpy(buf, "00100.1000001")), "100.1000001"));
	assert(!strcmp(libsimple_minimise_number_string(strcpy(buf, "00100.0")), "100"));
	assert(!strcmp(libsimple_minimise_number_string(strcpy(buf, "00100.")), "100"));
	assert(!strcmp(libsimple_minimise_number_string(strcpy(buf, "100.00000")), "100"));
	assert(!strcmp(libsimple_minimise_number_string(strcpy(buf, "100.1")), "100.1"));
	assert(!strcmp(libsimple_minimise_number_string(strcpy(buf, "100.000001")), "100.000001"));
	assert(!strcmp(libsimple_minimise_number_string(strcpy(buf, "100.1000001")), "100.1000001"));
	assert(!strcmp(libsimple_minimise_number_string(strcpy(buf, "100.0")), "100"));
	assert(!strcmp(libsimple_minimise_number_string(strcpy(buf, "100.")), "100"));
	assert(!strcmp(libsimple_minimise_number_string(strcpy(buf, "0.00000")), "0"));
	assert(!strcmp(libsimple_minimise_number_string(strcpy(buf, "0.1")), "0.1"));
	assert(!strcmp(libsimple_minimise_number_string(strcpy(buf, "0.000001")), "0.000001"));
	assert(!strcmp(libsimple_minimise_number_string(strcpy(buf, "0.1000001")), "0.1000001"));
	assert(!strcmp(libsimple_minimise_number_string(strcpy(buf, "0.0")), "0"));
	assert(!strcmp(libsimple_minimise_number_string(strcpy(buf, "0.")), "0"));
	assert(!strcmp(libsimple_minimise_number_string(strcpy(buf, ".00000")), "0"));
	assert(!strcmp(libsimple_minimise_number_string(strcpy(buf, ".1")), ".1"));
	assert(!strcmp(libsimple_minimise_number_string(strcpy(buf, ".000001")), ".000001"));
	assert(!strcmp(libsimple_minimise_number_string(strcpy(buf, ".1000001")), ".1000001"));
	assert(!strcmp(libsimple_minimise_number_string(strcpy(buf, ".0")), "0"));

	assert(!strcmp(libsimple_minimise_number_string(strcpy(buf, "+00100.00000")), "100"));
	assert(!strcmp(libsimple_minimise_number_string(strcpy(buf, "+00100.1")), "100.1"));
	assert(!strcmp(libsimple_minimise_number_string(strcpy(buf, "+00100.000001")), "100.000001"));
	assert(!strcmp(libsimple_minimise_number_string(strcpy(buf, "+00100.1000001")), "100.1000001"));
	assert(!strcmp(libsimple_minimise_number_string(strcpy(buf, "+00100.0")), "100"));
	assert(!strcmp(libsimple_minimise_number_string(strcpy(buf, "+00100.")), "100"));
	assert(!strcmp(libsimple_minimise_number_string(strcpy(buf, "+100.00000")), "100"));
	assert(!strcmp(libsimple_minimise_number_string(strcpy(buf, "+100.1")), "100.1"));
	assert(!strcmp(libsimple_minimise_number_string(strcpy(buf, "+100.000001")), "100.000001"));
	assert(!strcmp(libsimple_minimise_number_string(strcpy(buf, "+100.1000001")), "100.1000001"));
	assert(!strcmp(libsimple_minimise_number_string(strcpy(buf, "+100.0")), "100"));
	assert(!strcmp(libsimple_minimise_number_string(strcpy(buf, "+100.")), "100"));
	assert(!strcmp(libsimple_minimise_number_string(strcpy(buf, "+0.00000")), "0"));
	assert(!strcmp(libsimple_minimise_number_string(strcpy(buf, "+0.1")), "0.1"));
	assert(!strcmp(libsimple_minimise_number_string(strcpy(buf, "+0.000001")), "0.000001"));
	assert(!strcmp(libsimple_minimise_number_string(strcpy(buf, "+0.1000001")), "0.1000001"));
	assert(!strcmp(libsimple_minimise_number_string(strcpy(buf, "+0.0")), "0"));
	assert(!strcmp(libsimple_minimise_number_string(strcpy(buf, "+0.")), "0"));
	assert(!strcmp(libsimple_minimise_number_string(strcpy(buf, "+.00000")), "0"));
	assert(!strcmp(libsimple_minimise_number_string(strcpy(buf, "+.1")), ".1"));
	assert(!strcmp(libsimple_minimise_number_string(strcpy(buf, "+.000001")), ".000001"));
	assert(!strcmp(libsimple_minimise_number_string(strcpy(buf, "+.1000001")), ".1000001"));
	assert(!strcmp(libsimple_minimise_number_string(strcpy(buf, "+.0")), "0"));

	assert(!strcmp(libsimple_minimise_number_string(strcpy(buf, "-00100.00000")), "-100"));
	assert(!strcmp(libsimple_minimise_number_string(strcpy(buf, "-00100.1")), "-100.1"));
	assert(!strcmp(libsimple_minimise_number_string(strcpy(buf, "-00100.000001")), "-100.000001"));
	assert(!strcmp(libsimple_minimise_number_string(strcpy(buf, "-00100.1000001")), "-100.1000001"));
	assert(!strcmp(libsimple_minimise_number_string(strcpy(buf, "-00100.0")), "-100"));
	assert(!strcmp(libsimple_minimise_number_string(strcpy(buf, "-00100.")), "-100"));
	assert(!strcmp(libsimple_minimise_number_string(strcpy(buf, "-100.00000")), "-100"));
	assert(!strcmp(libsimple_minimise_number_string(strcpy(buf, "-100.1")), "-100.1"));
	assert(!strcmp(libsimple_minimise_number_string(strcpy(buf, "-100.000001")), "-100.000001"));
	assert(!strcmp(libsimple_minimise_number_string(strcpy(buf, "-100.1000001")), "-100.1000001"));
	assert(!strcmp(libsimple_minimise_number_string(strcpy(buf, "-100.0")), "-100"));
	assert(!strcmp(libsimple_minimise_number_string(strcpy(buf, "-100.")), "-100"));
	assert(!strcmp(libsimple_minimise_number_string(strcpy(buf, "-0.00000")), "-0"));
	assert(!strcmp(libsimple_minimise_number_string(strcpy(buf, "-0.1")), "-0.1"));
	assert(!strcmp(libsimple_minimise_number_string(strcpy(buf, "-0.000001")), "-0.000001"));
	assert(!strcmp(libsimple_minimise_number_string(strcpy(buf, "-0.1000001")), "-0.1000001"));
	assert(!strcmp(libsimple_minimise_number_string(strcpy(buf, "-0.0")), "-0"));
	assert(!strcmp(libsimple_minimise_number_string(strcpy(buf, "-0.")), "-0"));
	assert(!strcmp(libsimple_minimise_number_string(strcpy(buf, "-.00000")), "-0"));
	assert(!strcmp(libsimple_minimise_number_string(strcpy(buf, "-.1")), "-.1"));
	assert(!strcmp(libsimple_minimise_number_string(strcpy(buf, "-.000001")), "-.000001"));
	assert(!strcmp(libsimple_minimise_number_string(strcpy(buf, "-.1000001")), "-.1000001"));
	assert(!strcmp(libsimple_minimise_number_string(strcpy(buf, "-.0")), "-0"));

	return 0;
}

#endif
