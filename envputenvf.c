/* See LICENSE file for copyright and license details. */
#include "libsimple.h"
#ifndef TEST


void
libsimple_envputenvf(int status, const char *fmt, va_list ap)
{
	if (libsimple_vputenvf(fmt, ap))
		enprintf(status, "putenvf:");
}


#else
#include "test.h"

int
main(void)
{
	eputenvf("X=xyz");
	assert(!strcmpnul(getenv("X"), "xyz"));
	eputenvf("Y=xyz");
	assert(!strcmpnul(getenv("Y"), "xyz"));

	eputenvf("X=x%sz", "abc");
	assert(!strcmpnul(getenv("X"), "xabcz"));
	eputenvf("Y=x%sz", "abc");
	assert(!strcmpnul(getenv("Y"), "xabcz"));

	eputenvf("X=%ix%sz%i", 10, "abc", -11);
	assert(!strcmpnul(getenv("X"), "10xabcz-11"));
	eputenvf("Y=%ix%sz%i", 10, "abc", -11);
	assert(!strcmpnul(getenv("Y"), "10xabcz-11"));

	enputenvf(1, "X=xyz");
	assert(!strcmpnul(getenv("X"), "xyz"));
	enputenvf(1, "Y=xyz");
	assert(!strcmpnul(getenv("Y"), "xyz"));

	enputenvf(1, "X=x%sz", "abc");
	assert(!strcmpnul(getenv("X"), "xabcz"));
	enputenvf(1, "Y=x%sz", "abc");
	assert(!strcmpnul(getenv("Y"), "xabcz"));

	enputenvf(1, "X=%ix%sz%i", 10, "abc", -11);
	assert(!strcmpnul(getenv("X"), "10xabcz-11"));
	enputenvf(1, "Y=%ix%sz%i", 10, "abc", -11);
	assert(!strcmpnul(getenv("Y"), "10xabcz-11"));

	if (have_custom_malloc()) {
		alloc_fail_in = 1;
		assert_exit(enputenvf(100, "X=xyz"));
		assert(exit_status == 100);
		assert_stderr("%s: putenvf: %s\n", argv0, strerror(ENOMEM));
		assert(!alloc_fail_in);

		libsimple_default_failure_exit = 102;
		alloc_fail_in = 1;
		assert_exit(eputenvf("X=xyz"));
		assert(exit_status == 102);
		assert_stderr("%s: putenvf: %s\n", argv0, strerror(ENOMEM));
		assert(!alloc_fail_in);
	}

	return 0;
}

#endif
