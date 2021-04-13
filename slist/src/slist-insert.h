#ifndef MUST__SLIST_INSERT_H
#define MUST__SLIST_INSERT_H

#include <stddef.h> /* size_t */

#include "def.h"
#include "slist-types.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Inserting nodes into the singly linked list */
#define must_slist_put_front(SUFFIX) MUST__DEF3(slist, put_front, SUFFIX)
#define must_slist_put_after(SUFFIX) MUST__DEF3(slist, put_after, SUFFIX)
#define must_slist_put(SUFFIX)	     MUST__DEF3(slist, put, SUFFIX)

void must_slist_put_front(SUFFIX)(must_slist(SUFFIX) *slist,
				  must_slist_node(SUFFIX) *node);
void must_slist_put_after(SUFFIX)(must_slist(SUFFIX) *slist,
				  must_slist_node(SUFFIX) *node_after,
				  must_slist_node(SUFFIX) *new_node);
void must_slist_put(SUFFIX)(must_slist(SUFFIX) *slist, size_t index,
			    must_slist_node(SUFFIX) *node);

#ifdef __cplusplus
}
#endif

#endif
