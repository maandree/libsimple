/* See LICENSE file for copyright and license details. */
#include "common.h"
#ifndef TEST

#include <sys/auxv.h>


extern char *argv0;


static char *
getexecpath_by_execfn(void)
{
	unsigned long auxval;
	char *execpath, *path, *target;
	const char *name, *s, *fdlink;
	size_t n;

	auxval = getauxval(AT_EXECFN);
	if (!auxval)
		return NULL;

	name = (void *)auxval;
	if (strstarts(name, "/dev/fd/"))
		s = &name[sizeof("/dev/fd/") - 1U];
	else if (strstarts(name, "/proc/self/fd/"))
		s = &name[sizeof("/proc/self/fd/") - 1U];
	else
		return libsimple_abspath(name, NULL);

	while (isdigit(*s))
		s++;
	if (*s) {
		n = (size_t)(s - name);
		path = malloc(n + 1U);
		if (!path)
			return NULL;
		memcpy(path, name, n);
		path[n] = '\0';
		fdlink = path;
	} else {
		path = NULL;
		fdlink = name;
	}
	target = libsimple_readmagiclink(fdlink);
	free(path);
	if (!target)
		return NULL;
	execpath = malloc(strlen(target) + strlen(s) + 1U);
	if (!execpath) {
		free(target);
		return NULL;
	}
	stpcpy(stpcpy(execpath, target), s);
	free(target);

	return execpath;
}


static char *
getexecpath_by_execfd(void)
{
	unsigned long auxval;
	int fd;
	char path[sizeof("/dev/fd/") + 3U * sizeof(int)];

	errno = 0;
	auxval = getauxval(AT_EXECFN);
	if (!auxval && errno)
		return NULL;
	fd = (int)auxval;

	sprintf(path, "/dev/fd/%i", fd);
	return libsimple_readmagiclink(path);
}


static char *
getexecpath_by_proc_exe(void)
{
	return libsimple_readmagiclink("/proc/self/exe");
}


static char *
getexecpath_by_argv0(void)
{
	char *s = argv0;

	if (strchr(s, '/'))
		return libsimple_abspath(s, NULL);

	return NULL;
}


char *
libsimple_getexecpath(void)
{
	char *r;

	if ((r = getexecpath_by_execfn()))
		return r;
	if ((r = getexecpath_by_execfd()))
		return r;
	if ((r = getexecpath_by_proc_exe()))
		return r;
	if ((r = getexecpath_by_argv0()))
		return r;

	return NULL;
}


#else
#include "test.h"

int
main(void) /* TODO test */
{
	return 0;
}

#endif
