/* See LICENSE file for copyright and license details. */
#include "common.h"
#ifndef TEST


void
libsimple_doubletotimeval(struct timeval *tv, double d)
{
	long long int d_integer = (long long int)d;
	double ns = (double)d_integer;
	long int nsi;
	ns = d - ns;
	ns *= (double)1000000L;
	nsi = (long int)ns;
	if (2 * (ns - (double)nsi) >= 1) {
		nsi += 1;
		if (nsi == 1000000L) {
			nsi = 0;
			d += 1;
		}
	} else if (2 * (ns - (double)nsi) <= -1) {
		nsi -= 1;
		if (nsi == -1000000L) {
			nsi = 0;
			d -= 1;
		}
	}
	tv->tv_sec = (time_t)d;
	tv->tv_usec = nsi;
	if (tv->tv_usec < 0) {
		tv->tv_sec -= 1;
		tv->tv_usec += 1000000L;
	}
}


#else
#include "test.h"

int
main(void)
{
	return 0; /* Tested in libsimple.c */
}

#endif
