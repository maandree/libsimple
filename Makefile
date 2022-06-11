.POSIX:

CONFIGFILE = config.mk
include $(CONFIGFILE)

SUBHDR =\
	libsimple/aligned_alloc.h\
	libsimple/aligned_allocz.h\
	libsimple/aligned_memdup.h\
	libsimple/aligned_realloc.h\
	libsimple/aligned_strdup.h\
	libsimple/aligned_strndup.h\
	libsimple/aligned_wcsdup.h\
	libsimple/aligned_wcsndup.h\
	libsimple/aligned_wmemdup.h\
	libsimple/array.h\
	libsimple/calloc.h\
	libsimple/definitions.h\
	libsimple/env.h\
	libsimple/malloc.h\
	libsimple/mallocz.h\
	libsimple/mem.h\
	libsimple/memalign.h\
	libsimple/memalignz.h\
	libsimple/memalloc.h\
	libsimple/memdup.h\
	libsimple/memelem.h\
	libsimple/overflow.h\
	libsimple/posix_memalign.h\
	libsimple/posix_memalignz.h\
	libsimple/printf.h\
	libsimple/pvalloc.h\
	libsimple/pvallocz.h\
	libsimple/realloc.h\
	libsimple/str.h\
	libsimple/strdup.h\
	libsimple/strn.h\
	libsimple/strndup.h\
	libsimple/strtoint.h\
	libsimple/time.h\
	libsimple/valloc.h\
	libsimple/vallocz.h\
	libsimple/wcsdup.h\
	libsimple/wcsndup.h\
	libsimple/wmemdup.h

HDR =\
	$(SUBHDR)\
	libsimple.h

OBJ =\
	aligned_memdup.o\
	aligned_strdup.o\
	aligned_strndup.o\
	aligned_wcsdup.o\
	aligned_wcsndup.o\
	aligned_wmemdup.o\
	allocn.o\
	asprintf.o\
	close.o\
	cmptimespec.o\
	cmptimeval.o\
	difftimespec.o\
	difftimeval.o\
	doubletotimespec.o\
	doubletotimeval.o\
	ealigned_memdup.o\
	ealigned_strdup.o\
	ealigned_strndup.o\
	ealigned_wcsdup.o\
	ealigned_wcsndup.o\
	ealigned_wmemdup.o\
	egmtime.o\
	elocaltime.o\
	ememalloc.o\
	ememdup.o\
	enaligned_allocz.o\
	enaligned_memdup.o\
	enaligned_realloc.o\
	enaligned_reallocarray.o\
	enaligned_strdup.o\
	enaligned_strndup.o\
	enaligned_wcsdup.o\
	enaligned_wcsndup.o\
	enaligned_wmemdup.o\
	encalloc.o\
	engmtime.o\
	enlocaltime.o\
	enmalloc.o\
	enmemalloc.o\
	enmemdup.o\
	enposix_memalign.o\
	enposix_memalignn.o\
	enposix_memalignz.o\
	enposix_memalignzn.o\
	enprintf.o\
	enputenvf.o\
	enpvalloc.o\
	enpvallocn.o\
	enpvallocz.o\
	enpvalloczn.o\
	enrealloc.o\
	enreallocarray.o\
	enreallocn.o\
	enstrdup.o\
	enstrndup.o\
	envaligned_alloczn.o\
	envaligned_reallocn.o\
	envallocz.o\
	envalloczn.o\
	envmalloczn.o\
	envmemalloc.o\
	envposix_memalignn.o\
	envposix_memalignzn.o\
	envputenvf.o\
	envpvallocn.o\
	envpvalloczn.o\
	envreallocn.o\
	envvalloczn.o\
	enwcsdup.o\
	enwcsndup.o\
	enwmemdup.o\
	eposix_memalign.o\
	eposix_memalignn.o\
	eposix_memalignz.o\
	eposix_memalignzn.o\
	eprintf.o\
	eputenvf.o\
	epvalloc.o\
	epvallocn.o\
	epvallocz.o\
	epvalloczn.o\
	erealloc.o\
	ereallocarray.o\
	ereallocn.o\
	estrdup.o\
	estrndup.o\
	evallocz.o\
	evalloczn.o\
	evmemalloc.o\
	evposix_memalignn.o\
	evposix_memalignzn.o\
	evputenvf.o\
	evpvallocn.o\
	evpvalloczn.o\
	evreallocn.o\
	evvalloczn.o\
	ewcsdup.o\
	ewcsndup.o\
	ewmemdup.o\
	getenv_e.o\
	getenv_ne.o\
	gmtime.o\
	localtime.o\
	memalloc.o\
	memcasechr.o\
	memcasechr_inv.o\
	memcasecmp.o\
	memcaseends.o\
	memcaseeq.o\
	memcaseeqlen.o\
	memcasemem.o\
	memcasescan.o\
	memcasescan_inv.o\
	memcasestarts.o\
	memchr_inv.o\
	memcmove.o\
	memdup.o\
	memelem.o\
	memelem_inv.o\
	memelemcpy.o\
	memelemmove.o\
	memelemscan.o\
	memelemscan_inv.o\
	memends.o\
	memeq.o\
	memeqlen.o\
	memisutf8.o\
	memmem.o\
	mempcpy.o\
	mempmove.o\
	mempset.o\
	mempsetelem.o\
	memptolower.o\
	memptoupper.o\
	memrcasechr.o\
	memrcasechr_inv.o\
	memrcaseeqlen.o\
	memrcasemem.o\
	memrchr.o\
	memrchr_inv.o\
	memrelem.o\
	memrelem_inv.o\
	memreplace.o\
	memreplaceelem.o\
	memreqlen.o\
	memrmem.o\
	memscan.o\
	memscan_inv.o\
	memsetelem.o\
	memstarts.o\
	memtolower.o\
	memtoupper.o\
	minimise_number_string.o\
	multimespec.o\
	multimeval.o\
	posix_memalignn.o\
	posix_memalignz.o\
	posix_memalignzn.o\
	putenvf.o\
	pvalloc.o\
	pvallocn.o\
	pvallocz.o\
	pvalloczn.o\
	rawmemcasechr.o\
	rawmemcasechr_inv.o\
	rawmemccpy.o\
	rawmemchr.o\
	rawmemchr_inv.o\
	rawmemcmove.o\
	rawmemelem.o\
	rawmemelem_inv.o\
	rawmemelemcpy.o\
	rawmemelemmove.o\
	rawmemrcasechr.o\
	rawmemrcasechr_inv.o\
	rawmemrchr.o\
	rawmemrchr_inv.o\
	rawmemrelem.o\
	rawmemrelem_inv.o\
	reallocarray.o\
	reallocarrayf.o\
	reallocf.o\
	reallocfn.o\
	reallocn.o\
	stpntolower.o\
	stpntoupper.o\
	stptolower.o\
	stptoupper.o\
	strcasechr.o\
	strcasechr_inv.o\
	strcasechrnul.o\
	strcasechrnul_inv.o\
	strcaseends.o\
	strcaseeqlen.o\
	strcasestr.o\
	strchr_inv.o\
	strchrnul.o\
	strchrnul_inv.o\
	strcmove.o\
	strends.o\
	streqlen.o\
	strncasechr.o\
	strncasechr_inv.o\
	strncasechrnul.o\
	strncasechrnul_inv.o\
	strncaseends.o\
	strncaseeqlen.o\
	strncasestarts.o\
	strncasestr.o\
	strnchr.o\
	strnchr_inv.o\
	strnchrnul.o\
	strnchrnul_inv.o\
	strncmove.o\
	strnend.o\
	strnends.o\
	strneqlen.o\
	strnstarts.o\
	strnstr.o\
	strrcasechr.o\
	strrcasechr_inv.o\
	strrcasestr.o\
	strrchr_inv.o\
	strrncasechr.o\
	strrncasechr_inv.o\
	strrncasestr.o\
	strrnchr.o\
	strrnchr_inv.o\
	strrnstr.o\
	strrstr.o\
	strstarts.o\
	strtoh.o\
	strtohh.o\
	strtoi.o\
	strtoi16.o\
	strtoi32.o\
	strtoi64.o\
	strtoi8.o\
	strtotimespec.o\
	strtotimeval.o\
	strtou.o\
	strtou16.o\
	strtou32.o\
	strtou64.o\
	strtou8.o\
	strtouh.o\
	strtouhh.o\
	strtouz.o\
	strtoz.o\
	sumtimespec.o\
	sumtimeval.o\
	timespec2timeval.o\
	timespectodouble.o\
	timespectostr.o\
	timeval2timespec.o\
	timevaltodouble.o\
	timevaltostr.o\
	unlist.o\
	vallocz.o\
	valloczn.o\
	vasprintf.o\
	venprintf.o\
	veprintf.o\
	vmemalloc.o\
	vposix_memalignn.o\
	vputenvf.o\
	vpvallocn.o\
	vpvalloczn.o\
	vreallocfn.o\
	vvalloczn.o\
	vweprintf.o\
	wcsndup.o\
	weprintf.o\
	wmemdup.o\
	libsimple.o

MAN0 =\
	man0/libsimple-arg.h.0\
	man0/libsimple.h.0

MAN3 =\
	man3/libsimple_*.3\
	man3/LIBSIMPLE_*.3\
	man3/*.3libsimple

TESTS = $(OBJ:.o=.test) libsimple-arg.test

all: libsimple.a $(TESTS)
tests: $(TESTS)
$(OBJ): $(HDR)
$(TESTS): test.o libsimple.a
$(TESTS:.test=.to): $(HDR) test.h

test.o: test.c $(HDR) test.h
	$(CC) -c -o $@ test.c $(CFLAGS) -DTEST -O0 -ffreestanding

libsimple.a: $(OBJ)
	@rm -f -- $@
	$(AR) rc $@ $(OBJ)
	$(AR) -s $@

.to.test:
	$(CC) -o $@ $< test.o libsimple.a $(LDFLAGS)

.c.to:
	$(CC) -c -o $@ $< $(CFLAGS) -DTEST -O0

check: $(TESTS)
	@set -e; for t in $(TESTS); do printf '%s\n' "./$$t"; $(CHECK_PREFIX) "./$$t"; done

install: libsimple.a
	mkdir -p -- "$(DESTDIR)$(PREFIX)/lib"
	mkdir -p -- "$(DESTDIR)$(PREFIX)/include/libsimple"
	mkdir -p -- "$(DESTDIR)$(PREFIX)/share/man/man0"
	mkdir -p -- "$(DESTDIR)$(PREFIX)/share/man/man3"
	cp -- libsimple.a "$(DESTDIR)$(PREFIX)/lib"
	cp -- libsimple.h "$(DESTDIR)$(PREFIX)/include"
	cp -- libsimple-arg.h "$(DESTDIR)$(PREFIX)/include"
	cp -- $(SUBHDR) "$(DESTDIR)$(PREFIX)/include/libsimple"
	cp -- $(MAN0) "$(DESTDIR)$(PREFIX)/share/man/man0"
	cp -P -- $(MAN3) "$(DESTDIR)$(PREFIX)/share/man/man3"

uninstall:
	-rm -f -- "$(DESTDIR)$(PREFIX)/lib/libsimple.a"
	-rm -f -- "$(DESTDIR)$(PREFIX)/include/libsimple.h"
	-rm -f -- "$(DESTDIR)$(PREFIX)/include/libsimple-arg.h"
	-rm -rf -- "$(DESTDIR)$(PREFIX)/include/libsimple"
	-cd -- "$(DESTDIR)$(PREFIX)/share/man" && rm -f -- $(MAN0) $(MAN3)

clean:
	-rm -rf -- *.o *.su *.a *.so *.so.* *.gch *.gcda *.gcno *.gcov *.lo *.test *.to

.SUFFIXES:
.SUFFIXES: .test .to .o .c

.PHONY: all check install uninstall clean
