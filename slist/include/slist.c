#ifdef TYPE

#ifndef SUFFIX
#define SUFFIX TYPE
#endif

/* So we won't have mutiple inclusion problems. */
#define MUST__NO_UNDEF
#include "slist"
#undef MUST__NO_UNDEF

#include "slist-find.c"
#include "slist-insert.c"
#include "slist-mem.c"
#include "slist-undef.h"

#endif
