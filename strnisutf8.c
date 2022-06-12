/* See LICENSE file for copyright and license details. */
#include "common.h"
#ifndef TEST


extern inline int libsimple_strnisutf8(const char *, size_t, int);


#else
#include "test.h"

int
main(void)
{
#define ASSERT(STRING, GOOD)\
	do {\
		assert(libsimple_strnisutf8(STRING, sizeof(STRING) - 1, i) == (GOOD));\
		assert(libsimple_strnisutf8(STRING "\xFF", sizeof(STRING) - 1, i) == (GOOD));\
		assert(libsimple_strnisutf8(STRING "\x00", sizeof(STRING) - 1, i) == (GOOD));\
	} while (0)

	int i;
	for (i = 0; i < 2; i++) {
		ASSERT("", 1);
		ASSERT("a", 1);
		ASSERT("abc", 1);
		ASSERT("123", 1);
		ASSERT("åäö", 1);
		ASSERT("𝖆𝖇𝖈", 1);
		ASSERT("\x1b", 1);
		ASSERT("\n\r\t\f", 1);
		ASSERT("\xFF", 0);
		ASSERT("\x01", 1);
		ASSERT("\x7F", 1);
		ASSERT("\x80", 0);
		ASSERT("\xC0", 0);
		ASSERT("\xC0\x80", i);
		ASSERT("\xC0\x81", 0);
		ASSERT("\xCF", 0);
		ASSERT("\xEF", 0);
		ASSERT("\xEF\x8F", 0);
		ASSERT("\xF7", 0);
		ASSERT("\xF7\x8F", 0);
		ASSERT("\xF7\x8F\x8F", 0);
		ASSERT("\xFA", 0);
		ASSERT("\xFA\x8F", 0);
		ASSERT("\xFA\x8F\x8F", 0);
		ASSERT("\xFA\x8F\x8F\x8F", 0);
		ASSERT("\xFD", 0);
		ASSERT("\xFD\x8F", 0);
		ASSERT("\xFD\x8F\x8F", 0);
		ASSERT("\xFD\x8F\x8F\x8F", 0);
		ASSERT("\xFD\x8F\x8F\x8F\x8F", 0);
		ASSERT("\xFE", 0);
		ASSERT("\xFE\x8F", 0);
		ASSERT("\xFE\x8F\x8F", 0);
		ASSERT("\xFE\x8F\x8F\x8F", 0);
		ASSERT("\xFE\x8F\x8F\x8F\x8F", 0);
		ASSERT("\xFE\x8F\x8F\x8F\x8F\x8F", 0);
		ASSERT("\xFF", 0);
		ASSERT("\xFF\x8F", 0);
		ASSERT("\xFF\x8F\x8F", 0);
		ASSERT("\xFF\x8F\x8F\x8F", 0);
		ASSERT("\xFF\x8F\x8F\x8F\x8F", 0);
		ASSERT("\xFF\x8F\x8F\x8F\x8F\x8F", 0);
		ASSERT("\xFF\x8F\x8F\x8F\x8F\x8F\x8F", 0);
		ASSERT("\xC1\x80", 0);
		ASSERT("\xC2\x80", 1);
		ASSERT("\xE1\x80\x80\x80", 0);
		ASSERT("\xE1\x80\xC0\x80", 0);
		ASSERT("\xE1\x80\x00\x80", 0);
		ASSERT("\xF1\x80\x80\x80", 1);
		ASSERT("\xFF\x80\x80\x80\x80\x80\x80\x80", 0);
	}
	return 0;
}

#endif
