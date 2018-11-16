/* See LICENSE file for copyright and license details. */
#include "libsimple.h"
#ifndef TEST


int
libsimple_memisutf8(const char *string, size_t n, int allow_modified_nul)
{
	static long BYTES_TO_MIN_BITS[] = {0, 0,  8, 12, 17, 22, 27};
        static long BYTES_TO_MAX_BITS[] = {0, 7, 11, 16, 21, 26, 31};
        long int bytes = 0, read_bytes = 0, bits = 0, c, character;
	size_t i;

        /*                                                      min bits  max bits
          0.......                                                 0         7
          110..... 10......                                        8        11
          1110.... 10...... 10......                              12        16
          11110... 10...... 10...... 10......                     17        21
          111110.. 10...... 10...... 10...... 10......            22        26
          1111110. 10...... 10...... 10...... 10...... 10......   27        31
        */

	for (i = 0; i < n; i++) {
		c = (long int)string[i];

                if (!read_bytes) {
                        /* First byte of the character. */

                        if (!(c & 0x80))
                                /* Single-byte character. */
                                continue;

                        if ((c & 0xC0) == 0x80)
                                /* Single-byte character marked as multibyte, or
                                   a non-first byte in a multibyte character. */
                                return 0;

                        /* Multibyte character. */
                        while ((c & 0x80))
                                bytes++, c <<= 1;
                        read_bytes = 1;
			character = (c & 0xFF) >> bytes;
                        if (bytes > 6)
                                /* 31-bit characters can be encoded with 6-bytes,
                                   and UTF-8 does not cover higher code points. */
                                return 0;
                } else {
                        /* Not first byte of the character. */

                        if ((c & 0xC0) != 0x80)
                                /* Beginning of new character before a
                                   multibyte character has ended. */
                                return 0;

                        character = (character << 6) | (c & 0x7F);

                        if (++read_bytes < bytes)
                                /* Not at last byte yet. */
                                continue;

                        /* Check that the character is not unnecessarily long. */
                        while (character)
                                character >>= 1, bits++;
                        bits = (!bits && bytes == 2 && allow_modified_nul) ? 8 : bits;
                        if (bits < BYTES_TO_MIN_BITS[bytes] || BYTES_TO_MAX_BITS[bytes] < bits)
                                return 0;

                        read_bytes = bytes = bits = 0;
                }
        }

        /* Make sure we did not stop at the middle of a multibyte character. */
        return !read_bytes;
}


#else
#include "test.h"

int
main(void)
{
#define ASSERT(STRING, GOOD)\
	do {\
		assert(libsimple_memisutf8(STRING, sizeof(STRING) - 1, i) == (GOOD));\
		assert(libsimple_memisutf8(STRING "\xFF", sizeof(STRING) - 1, i) == (GOOD));\
		assert(libsimple_memisutf8(STRING "\x00", sizeof(STRING) - 1, i) == (GOOD));\
		assert(libsimple_strisutf8(STRING, i) == (GOOD));\
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
		assert(libsimple_memisutf8("\0abc", sizeof("\0abc") - 1, i) == 1);
		assert(libsimple_memisutf8("\0abc\x80", sizeof("\0abc\x80") - 1, i) == 0);
	}
	return 0;
}

#endif
