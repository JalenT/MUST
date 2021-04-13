#ifndef MUST__SLIST_FIND_H
#define MUST__SLIST_FIND_H

#include <stddef.h> /* size_t */

#include "def.h"
#include "slist-types.h"

#ifdef __cplusplus
extern "C" {
#endif

#define must_slist_get_node(SUFFIX)  MUST__DEF3(slist, get_node, SUFFIX)
#define must_slist_find_node(SUFFIX) MUST__DEF3(slist, find_node, SUFFIX)

must_slist_node(SUFFIX) *must_slist_get_node(SUFFIX)(must_slist(SUFFIX) *slist,
						     size_t index);

must_slist_node(SUFFIX) *must_slist_find_node(SUFFIX)(must_slist(SUFFIX) *slist,
						      TYPE data);

#ifdef __cplusplus
}
#endif

#endif
