#ifndef MUST__SLIST_MEM_H
#define MUST__SLIST_MEM_H

#include "def.h"
#include "slist-types.h"

#ifdef __cplusplus
extern "C" {
#endif

/*
 * create()/destroy()
 * new()/delete()
 */

#define must_slist_create(SUFFIX)  MUST__DEF3(slist, create, SUFFIX)
#define must_slist_destroy(SUFFIX) MUST__DEF3(slist, destroy, SUFFIX)

#define must_slist_new(SUFFIX)	  MUST__DEF3(slist, new, SUFFIX)
#define must_slist_delete(SUFFIX) MUST__DEF3(slist, delete, SUFFIX)

#define must_slist_node_create(SUFFIX)	MUST__DEF3(slist_node, create, SUFFIX)
#define must_slist_node_destroy(SUFFIX) MUST__DEF3(slist_node, destroy, SUFFIX)

#define must_slist_node_new(SUFFIX)    MUST__DEF3(slist_node, new, SUFFIX)
#define must_slist_node_delete(SUFFIX) MUST__DEF3(slist_node, delete, SUFFIX)

void must_slist_create(SUFFIX)(must_slist(SUFFIX) *slist);
void must_slist_destroy(SUFFIX)(must_slist(SUFFIX) **slist);

void must_slist_new(SUFFIX)(must_slist(SUFFIX) *slist);
void must_slist_delete(SUFFIX)(must_slist(SUFFIX) **slist);

void must_slist_node_create(SUFFIX)(must_slist_node(SUFFIX) *node);
void must_slist_node_destroy(SUFFIX)(must_slist_node(SUFFIX) **node);

void must_slist_node_new(SUFFIX)(must_slist_node(SUFFIX) *node, TYPE data);
void must_slist_node_delete(SUFFIX)(must_slist_node(SUFFIX) **node);

#ifdef __cplusplus
}
#endif

#endif
