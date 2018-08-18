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
	multimespec.o\
	multimeval.o\
	rawmemchr.o\
	rawmemrchr.o\
	rawmemrchr.o\
	recvfd.o\
	recvfrom_timestamped.o\
	sendfd.o\
	strcaseends.o\
	strcasestr.o\
	strchrnul.o\
	strends.o\
	strndup.o\
	strrcasestr.o\
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
	vputenvf.o\
	vweprintf.o\
	libsimple.o

TESTS =\
	asprintf.test\
	isutf8.test\
	memdup.test\
	memends.test\
	memmem.test\
	memrchr.test\
	memrmem.test\
	memstarts.test\
	rawmemchr.test\
	rawmemrchr.test\
	strcaseends.test\
	strcasestr.test\
	strends.test\
	strndup.test\
	strrcasestr.test\
	strrstr.test\
	strstarts.test\
	vasprintf.test

all: libsimple.a $(TESTS)
$(OBJ): $(@:.o=.c) libsimple.h
$(TESTS): $(@:=.o) libsimple.a
$(TESTS:=.o): $(@:.test.o=.c) libsimple.h test.h

libsimple.a: $(OBJ)
	$(AR) rc $@ $?
	$(AR) -s $@

.test.o.test:
	$(CC) -o $@ $< libsimple.a $(LDFLAGS)

.c.test.o:
	$(CC) -c -o $@ $< $(CFLAGS) -DTEST

check: $(TESTS)
	@set -e; for t in $(TESTS); do printf '%s\n' "./$$t"; "./$$t"; done

clean:
	-rm -rf -- *.o *.su *.a *.so *.so.* *.gch *.gcda *.gcno *.gcov *.lo *.test

.SUFFIXES:
.SUFFIXES: .test .test.o .o .c

.PHONY: all check clean
