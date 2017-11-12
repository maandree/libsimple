.POSIX:

CFLAGS = -std=c99 -Wall -Wextra -O2 $(CPPFLAGS)
CPPFLAGS = -D_DEFAULT_SOURCE -D_BSD_SOURCE -D_XOPEN_SOURCE=700
LDFLAGS = -s

OBJ =\
	allocn.o\
	asprintf.o\
	difftimespec.o\
	difftimeval.o\
	doubletotimespec.o\
	doubletotimeval.o\
	encalloc.o\
	enmalloc.o\
	enmemdup.o\
	enrealloc.o\
	enstrdup.o\
	enstrndup.o\
	envmalloczn.o\
	envputenvf.o\
	envreallocn.o\
	isutf8.o\
	memdup.o\
	memends.o\
	memmem.o\
	memrchr.o\
	memstarts.o\
	multimespec.o\
	multimeval.o\
	rawmemchr.o\
	rawmemrchr.o\
	rawmemrchr.o\
	recvfd.o\
	recvfrom_timestamped.o\
	sendfd.o\
	strcasestr.o\
	strchrnul.o\
	strends.o\
	strndup.o\
	strstarts.o\
	strtotimespec.o\
	strtotimeval.o\
	sumtimespec.o\
	sumtimeval.o\
	timespec2timeval.o\
	timespectostr.o\
	timevaltostr.o\
	vasprintf.o\
	vputenvf.o\
	vweprintf.o\
	libsimple.o

all: libsimple.a
$(OBJ): libsimple.h

libsimple.a: $(OBJ)
	$(AR) rc $@ $?
	$(AR) -s $@

clean:
	-rm -r -- *.o libsimple.a libsimple.so libsimple.so.*

.SUFFIXES: .c.o

.PHONY: all clean
