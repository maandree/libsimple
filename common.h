/* See LICENSE file for copyright and license details. */
#include "libsimple.h"

#if defined(__clang__)
# pragma clang diagnostic ignored "-Wdocumentation"
# pragma clang diagnostic ignored "-Wdocumentation-unknown-command"
# pragma clang diagnostic ignored "-Wreserved-identifier"
# pragma clang diagnostic ignored "-Wdisabled-macro-expansion"
# pragma clang diagnostic ignored "-Wc++98-compat"
# pragma clang diagnostic ignored "-Wcovered-switch-default"
#endif

#ifdef execveat
# undef execveat
#endif
