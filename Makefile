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

all: libsimple.a
$(OBJ): $(@:.o=.c) libsimple.h

libsimple.a: $(OBJ)
	$(AR) rc $@ $?
	$(AR) -s $@

clean:
	-rm -rf -- *.o *.su *.a *.so *.so.* *.gch *.gcda *.gcno *.gcov *.lo

.SUFFIXES:
.SUFFIXES: .o .c

.PHONY: all clean
