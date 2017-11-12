.POSIX:

all: libsimple.a
libsimple.o: libsimple.h
libsimple.a: libsimple.o

clean:
	-rm -r -- libsimple.o libsimple.a libsimple.so libsimple.so.*

.PHONY: all clean
