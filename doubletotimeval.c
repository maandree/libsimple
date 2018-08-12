/* See LICENSE file for copyright and license details. */
#include "libsimple.h"


void
libsimple_doubletotimeval(struct timeval *tv, double d) /* TODO test */
{
	double ns = (long long int)d;
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
	}
	tv->tv_sec = (time_t)d;
	tv->tv_usec = nsi;
}
