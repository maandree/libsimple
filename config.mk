PREFIX = /usr
MANPREFIX = $(PREFIX)/share/man

CPPFLAGS = -D_DEFAULT_SOURCE -D_BSD_SOURCE -D_XOPEN_SOURCE=700
CFLAGS   = -std=c11 -Wall -Wextra -O2 $(CPPFLAGS)
LDFLAGS  = -s
