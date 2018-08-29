.POSIX:

CONFIGFILE = config.mk
include $(CONFIGFILE)

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
	memrmem.o\
	memstarts.o\
	minimise_number_string.o\
	multimespec.o\
	multimeval.o\
	rawmemchr.o\
	rawmemrchr.o\
	rawmemrchr.o\
	strcaseends.o\
	strcasestr.o\
	strchrnul.o\
	strends.o\
	strndup.o\
	strnstr.o\
	strncasestr.o\
	strrcasestr.o\
	strrstr.o\
	strrncasestr.o\
	strrnstr.o\
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

TESTS = $(OBJ:.o=.test)

all: libsimple.a $(TESTS)
$(OBJ): $(@:.o=.c) libsimple.h
$(TESTS): $(@:=.o) test.o libsimple.a
$(TESTS:=.o): $(@:.test.o=.c) libsimple.h test.h
test.o: test.c libsimple.h test.h

libsimple.a: $(OBJ)
	$(AR) rc $@ $?
	$(AR) -s $@

.test.o.test:
	$(CC) -o $@ $< test.o libsimple.a $(LDFLAGS)

.c.test.o:
	$(CC) -c -o $@ $< $(CFLAGS) -DTEST

check: $(TESTS)
	@set -e; for t in $(TESTS); do printf '%s\n' "./$$t"; $(CHECK_PREFIX) "./$$t"; done

install: libsimple.a
	mkdir -p -- "$(DESTDIR)$(PREFIX)/lib"
	mkdir -p -- "$(DESTDIR)$(PREFIX)/include"
	cp -- libsimple.a "$(DESTDIR)$(PREFIX)/lib"
	cp -- libsimple.h "$(DESTDIR)$(PREFIX)/include"
	cp -- libsimple-arg.h "$(DESTDIR)$(PREFIX)/include"

uninstall:
	-rm -f -- "$(DESTDIR)$(PREFIX)/lib/libsimple.a"
	-rm -f -- "$(DESTDIR)$(PREFIX)/include/libsimple.h"
	-rm -f -- "$(DESTDIR)$(PREFIX)/include/libsimple-arg.h"

clean:
	-rm -rf -- *.o *.su *.a *.so *.so.* *.gch *.gcda *.gcno *.gcov *.lo *.test

.SUFFIXES:
.SUFFIXES: .test .test.o .o .c

.PHONY: all check install uninstall clean
