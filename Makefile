.POSIX:

CONFIGFILE = config.mk
include $(CONFIGFILE)

SUBHDR =\
	libsimple/definitions.h\
	libsimple/memalloc.h\
	libsimple/strdup.h\
	libsimple/strndup.h\
	libsimple/memdup.h\
	libsimple/aligned_memdup.h\
	libsimple/mallocz.h\
	libsimple/malloc.h\
	libsimple/calloc.h\
	libsimple/realloc.h\
	libsimple/memalignz.h\
	libsimple/memalign.h\
	libsimple/vallocz.h\
	libsimple/valloc.h\
	libsimple/pvallocz.h\
	libsimple/pvalloc.h\
	libsimple/aligned_allocz.h\
	libsimple/aligned_alloc.h\
	libsimple/posix_memalignz.h\
	libsimple/posix_memalign.h\
	libsimple/env.h\
	libsimple/time.h\
	libsimple/printf.h\
	libsimple/str.h\
	libsimple/strn.h\
	libsimple/mem.h

HDR =\
	$(SUBHDR)\
	libsimple.h

OBJ =\
	aligned_memdup.o\
	allocn.o\
	asprintf.o\
	difftimespec.o\
	difftimeval.o\
	doubletotimespec.o\
	doubletotimeval.o\
	enaligned_allocz.o\
	enaligned_memdup.o\
	encalloc.o\
	enmalloc.o\
	enmemdup.o\
	enposix_memalignz.o\
	enrealloc.o\
	enstrdup.o\
	enstrndup.o\
	envaligned_alloczn.o\
	envmalloczn.o\
	envmemalloc.o\
	envposix_memalignzn.o\
	envputenvf.o\
	envreallocn.o\
	isutf8.o\
	memcasechr.o\
	memcasecmp.o\
	memcaseends.o\
	memcaseeqlen.o\
	memcasemem.o\
	memcasestarts.o\
	memdup.o\
	memelem.o\
	memends.o\
	memeqlen.o\
	memmem.o\
	mempsetelem.o\
	memrcasechr.o\
	memrcaseeqlen.o\
	memrcasemem.o\
	memrchr.o\
	memrelem.o\
	memreqlen.o\
	memrmem.o\
	memstarts.o\
	minimise_number_string.o\
	multimespec.o\
	multimeval.o\
	rawmemcasechr.o\
	rawmemchr.o\
	rawmemrcasechr.o\
	rawmemrchr.o\
	strcasechr.o\
	strcasechrnul.o\
	strcaseends.o\
	strcaseeqlen.o\
	strcasestr.o\
	strchrnul.o\
	strends.o\
	streqlen.o\
	strncasechr.o\
	strncasechrnul.o\
	strncaseends.o\
	strncaseeqlen.o\
	strncasestarts.o\
	strncasestr.o\
	strnchr.o\
	strnchrnul.o\
	strnend.o\
	strnends.o\
	strneqlen.o\
	strnstarts.o\
	strnstr.o\
	strrcasechr.o\
	strrcasestr.o\
	strrncasechr.o\
	strrncasestr.o\
	strrnchr.o\
	strrnstr.o\
	strrstr.o\
	strstarts.o\
	strtotimespec.o\
	strtotimeval.o\
	sumtimespec.o\
	sumtimeval.o\
	timespec2timeval.o\
	timespectostr.o\
	timevaltostr.o\
	vasprintf.o\
	vmemalloc.o\
	vputenvf.o\
	vweprintf.o\
	libsimple.o

TESTS = $(OBJ:.o=.test)

all: libsimple.a $(TESTS)
$(OBJ): $(@:.o=.c) $(HDR)
$(TESTS): $(@:=.o) test.o libsimple.a
$(TESTS:=.o): $(@:.test.o=.c) $(HDR) test.h
test.o: test.c $(HDR) test.h

libsimple.a: $(OBJ)
	$(AR) rc $@ $?
	$(AR) -s $@

.test.o.test:
	$(CC) -o $@ $< test.o libsimple.a $(LDFLAGS)

.c.test.o:
	$(CC) -c -o $@ $< $(CFLAGS) -DTEST -O0

check: $(TESTS)
	@set -e; for t in $(TESTS); do printf '%s\n' "./$$t"; $(CHECK_PREFIX) "./$$t"; done

install: libsimple.a
	mkdir -p -- "$(DESTDIR)$(PREFIX)/lib"
	mkdir -p -- "$(DESTDIR)$(PREFIX)/include/libsimple"
	cp -- libsimple.a "$(DESTDIR)$(PREFIX)/lib"
	cp -- libsimple.h "$(DESTDIR)$(PREFIX)/include"
	cp -- libsimple-arg.h "$(DESTDIR)$(PREFIX)/include"
	cp -- $(SUBHDR) "$(DESTDIR)$(PREFIX)/include/libsimple"

uninstall:
	-rm -f -- "$(DESTDIR)$(PREFIX)/lib/libsimple.a"
	-rm -f -- "$(DESTDIR)$(PREFIX)/include/libsimple.h"
	-rm -f -- "$(DESTDIR)$(PREFIX)/include/libsimple-arg.h"
	-rm -rf -- "$(DESTDIR)$(PREFIX)/include/libsimple"

clean:
	-rm -rf -- *.o *.su *.a *.so *.so.* *.gch *.gcda *.gcno *.gcov *.lo *.test

.SUFFIXES:
.SUFFIXES: .test .test.o .o .c

.PHONY: all check install uninstall clean
