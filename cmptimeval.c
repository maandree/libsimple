/* See LICENSE file for copyright and license details. */
#include "common.h"
#ifndef TEST


extern inline int libsimple_cmptimeval(const struct timeval *, const struct timeval *);


#else
#include "test.h"

int
main(void)
{
	struct timeval tv1, tv2;

	tv1.tv_sec  = 0;
	tv1.tv_usec = 0L;
	tv2.tv_sec  = 0;
	tv2.tv_usec = 0L;
	assert(libsimple_cmptimeval(&tv1, &tv2) == 0);

	tv1.tv_sec  = 0;
	tv1.tv_usec = 1L;
	tv2.tv_sec  = 0;
	tv2.tv_usec = 0L;
	assert(libsimple_cmptimeval(&tv1, &tv2) == 1);

	tv1.tv_sec  = 0;
	tv1.tv_usec = 999999L;
	tv2.tv_sec  = 0;
	tv2.tv_usec = 0L;
	assert(libsimple_cmptimeval(&tv1, &tv2) == 1);

	tv1.tv_sec  = 0;
	tv1.tv_usec = 0L;
	tv2.tv_sec  = 0;
	tv2.tv_usec = 1L;
	assert(libsimple_cmptimeval(&tv1, &tv2) == -1);

	tv1.tv_sec  = 0;
	tv1.tv_usec = 1L;
	tv2.tv_sec  = 0;
	tv2.tv_usec = 1L;
	assert(libsimple_cmptimeval(&tv1, &tv2) == 0);

	tv1.tv_sec  = 0;
	tv1.tv_usec = 999999L;
	tv2.tv_sec  = 0;
	tv2.tv_usec = 1L;
	assert(libsimple_cmptimeval(&tv1, &tv2) == 1);

	tv1.tv_sec  = 0;
	tv1.tv_usec = 0L;
	tv2.tv_sec  = 0;
	tv2.tv_usec = 999999L;
	assert(libsimple_cmptimeval(&tv1, &tv2) == -1);

	tv1.tv_sec  = 0;
	tv1.tv_usec = 1L;
	tv2.tv_sec  = 0;
	tv2.tv_usec = 999999L;
	assert(libsimple_cmptimeval(&tv1, &tv2) == -1);

	tv1.tv_sec  = 0;
	tv1.tv_usec = 999999L;
	tv2.tv_sec  = 0;
	tv2.tv_usec = 999999L;
	assert(libsimple_cmptimeval(&tv1, &tv2) == 0);

	tv1.tv_sec  = 1;
	tv1.tv_usec = 0L;
	tv2.tv_sec  = 0;
	tv2.tv_usec = 0L;
	assert(libsimple_cmptimeval(&tv1, &tv2) == 1);

	tv1.tv_sec  = 1;
	tv1.tv_usec = 1L;
	tv2.tv_sec  = 0;
	tv2.tv_usec = 0L;
	assert(libsimple_cmptimeval(&tv1, &tv2) == 1);

	tv1.tv_sec  = 1;
	tv1.tv_usec = 0L;
	tv2.tv_sec  = 0;
	tv2.tv_usec = 1L;
	assert(libsimple_cmptimeval(&tv1, &tv2) == 1);

	tv1.tv_sec  = 1;
	tv1.tv_usec = 1L;
	tv2.tv_sec  = 0;
	tv2.tv_usec = 1L;
	assert(libsimple_cmptimeval(&tv1, &tv2) == 1);

	tv1.tv_sec  = 0;
	tv1.tv_usec = 0L;
	tv2.tv_sec  = 1;
	tv2.tv_usec = 0L;
	assert(libsimple_cmptimeval(&tv1, &tv2) == -1);

	tv1.tv_sec  = 0;
	tv1.tv_usec = 1L;
	tv2.tv_sec  = 1;
	tv2.tv_usec = 0L;
	assert(libsimple_cmptimeval(&tv1, &tv2) == -1);

	tv1.tv_sec  = 0;
	tv1.tv_usec = 0L;
	tv2.tv_sec  = 1;
	tv2.tv_usec = 1L;
	assert(libsimple_cmptimeval(&tv1, &tv2) == -1);

	tv1.tv_sec  = 0;
	tv1.tv_usec = 1L;
	tv2.tv_sec  = 1;
	tv2.tv_usec = 1L;
	assert(libsimple_cmptimeval(&tv1, &tv2) == -1);

	tv1.tv_sec  = 1;
	tv1.tv_usec = 0L;
	tv2.tv_sec  = 1;
	tv2.tv_usec = 0L;
	assert(libsimple_cmptimeval(&tv1, &tv2) == 0);

	tv1.tv_sec  = 1;
	tv1.tv_usec = 1L;
	tv2.tv_sec  = 1;
	tv2.tv_usec = 0L;
	assert(libsimple_cmptimeval(&tv1, &tv2) == 1);

	tv1.tv_sec  = 1;
	tv1.tv_usec = 0L;
	tv2.tv_sec  = 1;
	tv2.tv_usec = 1L;
	assert(libsimple_cmptimeval(&tv1, &tv2) == -1);

	tv1.tv_sec  = 1;
	tv1.tv_usec = 1L;
	tv2.tv_sec  = 1;
	tv2.tv_usec = 1L;
	assert(libsimple_cmptimeval(&tv1, &tv2) == 0);

	tv1.tv_sec  = -1;
	tv1.tv_usec = 0L;
	tv2.tv_sec  = 0;
	tv2.tv_usec = 0L;
	assert(libsimple_cmptimeval(&tv1, &tv2) == -1);

	tv1.tv_sec  = -1;
	tv1.tv_usec = 1L;
	tv2.tv_sec  = 0;
	tv2.tv_usec = 0L;
	assert(libsimple_cmptimeval(&tv1, &tv2) == -1);

	tv1.tv_sec  = -1;
	tv1.tv_usec = 0L;
	tv2.tv_sec  = 0;
	tv2.tv_usec = 1L;
	assert(libsimple_cmptimeval(&tv1, &tv2) == -1);

	tv1.tv_sec  = -1;
	tv1.tv_usec = 1L;
	tv2.tv_sec  = 0;
	tv2.tv_usec = 1L;
	assert(libsimple_cmptimeval(&tv1, &tv2) == -1);

	tv1.tv_sec  = 0;
	tv1.tv_usec = 0L;
	tv2.tv_sec  = -1;
	tv2.tv_usec = 0L;
	assert(libsimple_cmptimeval(&tv1, &tv2) == 1);

	tv1.tv_sec  = 0;
	tv1.tv_usec = 1L;
	tv2.tv_sec  = -1;
	tv2.tv_usec = 0L;
	assert(libsimple_cmptimeval(&tv1, &tv2) == 1);

	tv1.tv_sec  = 0;
	tv1.tv_usec = 0L;
	tv2.tv_sec  = -1;
	tv2.tv_usec = 1L;
	assert(libsimple_cmptimeval(&tv1, &tv2) == 1);

	tv1.tv_sec  = 0;
	tv1.tv_usec = 1L;
	tv2.tv_sec  = -1;
	tv2.tv_usec = 1L;
	assert(libsimple_cmptimeval(&tv1, &tv2) == 1);

	tv1.tv_sec  = -1;
	tv1.tv_usec = 0L;
	tv2.tv_sec  = -1;
	tv2.tv_usec = 0L;
	assert(libsimple_cmptimeval(&tv1, &tv2) == 0);

	tv1.tv_sec  = -1;
	tv1.tv_usec = 1L;
	tv2.tv_sec  = -1;
	tv2.tv_usec = 0L;
	assert(libsimple_cmptimeval(&tv1, &tv2) == 1);

	tv1.tv_sec  = -1;
	tv1.tv_usec = 0L;
	tv2.tv_sec  = -1;
	tv2.tv_usec = 1L;
	assert(libsimple_cmptimeval(&tv1, &tv2) == -1);

	tv1.tv_sec  = -1;
	tv1.tv_usec = 1L;
	tv2.tv_sec  = -1;
	tv2.tv_usec = 1L;
	assert(libsimple_cmptimeval(&tv1, &tv2) == 0);

	tv1.tv_sec  = 0;
	tv1.tv_usec = 0L;
	tv2.tv_sec  = TIME_MAX;
	tv2.tv_usec = 0L;
	assert(libsimple_cmptimeval(&tv1, &tv2) == -1);

	tv1.tv_sec  = 1;
	tv1.tv_usec = 0L;
	tv2.tv_sec  = TIME_MAX;
	tv2.tv_usec = 0L;
	assert(libsimple_cmptimeval(&tv1, &tv2) == -1);

	tv1.tv_sec  = TIME_MAX;
	tv1.tv_usec = 0L;
	tv2.tv_sec  = TIME_MAX;
	tv2.tv_usec = 0L;
	assert(libsimple_cmptimeval(&tv1, &tv2) == 0);

	tv1.tv_sec  = 1;
	tv1.tv_usec = 0L;
	tv2.tv_sec  = -1;
	tv2.tv_usec = 0L;
	assert(libsimple_cmptimeval(&tv1, &tv2) == 1);

	tv1.tv_sec  = -1;
	tv1.tv_usec = 0L;
	tv2.tv_sec  = 1;
	tv2.tv_usec = 0L;
	assert(libsimple_cmptimeval(&tv1, &tv2) == -1);

	return 0;
}

#endif
