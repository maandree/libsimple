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
                                return -1;

                        /* Multibyte character. */
                        while ((c & 0x80))
                                bytes++, c <<= 1;
                        read_bytes = 1;
                        character = c & 0x7F;
                        if (bytes > 6)
                                /* 31-bit characters can be encoded with 6-bytes,
                                   and UTF-8 does not cover higher code points. */
                                return -1;
                } else {
                        /* Not first byte of the character. */

                        if ((c & 0xC0) != 0x80)
                                /* Beginning of new character before a
                                   multibyte character has ended. */
                                return -1;

                        character = (character << 6) | (c & 0x7F);

                        if (++read_bytes < bytes)
                                /* Not at last byte yet. */
                                continue;

                        /* Check that the character is not unnecessarily long. */
                        while (character)
                                character >>= 1, bits++;
                        bits = (!bits && bytes == 2 && allow_modified_nul) ? 8 : bits;
                        if (bits < BYTES_TO_MIN_BITS[bytes] || BYTES_TO_MAX_BITS[bytes] < bits)
                                return -1;

                        read_bytes = bytes = bits = 0;
                }
        }

        /* Make sure we did not stop at the middle of a multibyte character. */
        return !read_bytes;
}
