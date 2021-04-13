#ifndef MUST__SLIST_TYPES_H
#define MUST__SLIST_TYPES_H

#include <stddef.h>

#include "def.h"

#ifdef __cplusplus
extern "C" {
#endif

#define must_slist(SUFFIX)	MUST__DEF2(slist, SUFFIX)
#define must_slist_node(SUFFIX) MUST__DEF2(slist_node, SUFFIX)

typedef struct must_slist_node(SUFFIX) must_slist_node(SUFFIX);
typedef struct must_slist(SUFFIX) must_slist(SUFFIX);

struct must_slist(SUFFIX)
{
	struct must_slist_node(SUFFIX) *head;
	size_t length;
};

struct must_slist_node(SUFFIX)
{
	TYPE data;
	struct must_slist_node(SUFFIX) *next;
};

#ifdef __cplusplus
}
#endif

#endif
