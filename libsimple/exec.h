/* See LICENSE file for copyright and license details. */

/* TODO man, doc, test */


const char *libsimple_which(const char *file, int cwdfd, const char *path, char **free_this_out);

int libsimple_xexecv(int dirfd, const char *file, int atflags, const char *path, char *const *envp, char *const *argv);

int libsimple_vxexecl(int dirfd, const char *file, int atflags, const char *path, char *const *envp, va_list argv_null);

int libsimple_xexecl(int dirfd, const char *file, int atflags, const char *path, char *const *envp, ... /* argv, NULL */);

int libsimple_vxexecle(int dirfd, const char *file, int atflags, const char *path, va_list argv_null_envp);

int libsimple_execlpe(const char *file, ... /* argv, NULL, char *const envp[] */);
#ifndef execlpe
# define execlpe libsimple_execlpe
#endif

int libsimple_vexecl(const char *pathname, va_list argv_null);
#ifndef vexecl
# define vexecl libsimple_vexecl
#endif

int libsimple_vexecle(const char *pathname, va_list argv_null_envp);
#ifndef vexecle
# define vexecle libsimple_vexecle
#endif

int libsimple_vexeclp(const char *file, va_list argv_null);
#ifndef vexeclp
# define vexeclp libsimple_vexeclp
#endif

int libsimple_vexeclpe(const char *file, va_list argv_null_envp);
#ifndef vexeclpe
# define vexeclpe libsimple_vexeclpe
#endif

int libsimple_execvpe(const char *file, char *const argv[], char *const envp[]);
#ifndef execvpe
# define execvpe libsimple_execvpe
#endif

int libsimple_vfexecl(int fd, va_list argv_null);
#ifndef vfexecl
# define vfexecl libsimple_vfexecl
#endif

int libsimple_vfexecle(int fd, va_list argv_null_envp);
#ifndef vfexecle
# define vfexecle libsimple_vfexecle
#endif

int libsimple_fexecl(int fd, ... /* argv, NULL */);
#ifndef fexecl
# define fexecl libsimple_fexecl
#endif

int libsimple_fexecle(int fd, ... /* argv, NULL, char *const envp[] */);
#ifndef fexecle
# define fexecle libsimple_fexecle
#endif

int libsimple_fexecv(int fd, char *const argv[]);
#ifndef fexecv
# define fexecv libsimple_fexecv
#endif

int libsimple_execveat(int dirfd, const char *pathname, char *const argv[], char *const envp[], int flags);
#ifndef execveat
# define execveat libsimple_execveat
#endif

int libsimple_execvat(int dirfd, const char *pathname, char *const argv[], int flags);
#ifndef execvat
# define execvat libsimple_execvat
#endif

int libsimple_execleat(int dirfd, const char *pathname, ... /* argv, NULL, char *const envp[], int flags */);
#ifndef execleat
# define execleat libsimple_execleat
#endif

int libsimple_execlat(int dirfd, const char *pathname, ... /* argv, NULL, int flags */);
#ifndef execlat
# define execlat libsimple_execlat
#endif

int libsimple_vexecleat(int dirfd, const char *pathname, va_list argv_null_envp_flags);
#ifndef vexecleat
# define vexecleat libsimple_execlpe
#endif

int libsimple_vexeclat(int dirfd, const char *pathname, va_list argv_null_flags);
#ifndef vexeclat
# define vexeclat libsimple_vexeclat
#endif
