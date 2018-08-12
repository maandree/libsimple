/* See LICENSE file for copyright and license details. */
#include "libsimple.h"


int
libsimple_isutf8(const char *string, int allow_modified_nul)
{
	static long BYTES_TO_MIN_BITS[] = {0, 0,  8, 12, 17, 22, 37};
        static long BYTES_TO_MAX_BITS[] = {0, 7, 11, 16, 21, 26, 31};
        long int bytes = 0, read_bytes = 0, bits = 0, c, character;

        /*                                                      min bits  max bits
          0.......                                                 0         7
          110..... 10......                                        8        11
          1110.... 10...... 10......                              12        16
          11110... 10...... 10...... 10......                     17        21
          111110.. 10...... 10...... 10...... 10......            22        26
          1111110. 10...... 10...... 10...... 10...... 10......   27        31
        */

	while ((c = (long int)(*string++))) {
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
                        character = c & 0x7F;
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


#ifdef TEST
#include <assert.h>

int
main(void)
{
	int i;
	for (i = 0; i < 2; i++) {
		assert(libsimple_isutf8("", i) == 1);
		assert(libsimple_isutf8("a", i) == 1);
		assert(libsimple_isutf8("abc", i) == 1);
		assert(libsimple_isutf8("123", i) == 1);
		assert(libsimple_isutf8("åäö", i) == 1);
		assert(libsimple_isutf8("𝖆𝖇𝖈", i) == 1);
		assert(libsimple_isutf8("\x1b", i) == 1);
		assert(libsimple_isutf8("\n\r\t\f", i) == 1);
		assert(libsimple_isutf8("\xFF", i) == 0);
		assert(libsimple_isutf8("\x01", i) == 1);
		assert(libsimple_isutf8("\x7F", i) == 1);
		assert(libsimple_isutf8("\x80", i) == 0);
		assert(libsimple_isutf8("\xC0", i) == 0);
		assert(libsimple_isutf8("\xC0\x80", i) == i);
		assert(libsimple_isutf8("\xC0\x81", i) == 0);
		assert(libsimple_isutf8("\xC1\x80", i) == 0);
		assert(libsimple_isutf8("\xC2\x80", i) == 1);
		assert(libsimple_isutf8("\xE1\x80\x80\x80", i) == 1);
		assert(libsimple_isutf8("\xE1\x80\xC0\x80", i) == 0);
		assert(libsimple_isutf8("\xE1\x80\x00\x80", i) == 0);
		assert(libsimple_isutf8("\xF1\x80\x80\x80", i) == 0);
		assert(libsimple_isutf8("\xFF\x80\x80\x80\x80\x80\x80\x80", i) == 0);
	}
	return 0;
}

#endif
