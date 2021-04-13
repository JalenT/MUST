#ifndef MUST__SLIST_MEM_H
#define MUST__SLIST_MEM_H

#include "def.h"
#include "slist-types.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Allocating memory for types */
#define must_slist_malloc(SUFFIX) MUST__DEF3(slist, malloc, SUFFIX)
#define must_slist_free(SUFFIX)   MUST__DEF3(slist, free, SUFFIX)

#define must_slist_new(SUFFIX)    MUST__DEF3(slist, new, SUFFIX)
#define must_slist_delete(SUFFIX) MUST__DEF3(slist, delete, SUFFIX)

#define must_slist_node_malloc(SUFFIX) MUST__DEF3(slist_node, malloc, SUFFIX)
#define must_slist_node_free(SUFFIX)   MUST__DEF3(slist_node, free, SUFFIX)

#define must_slist_node_new(SUFFIX)    MUST__DEF3(slist_node, new, SUFFIX)
#define must_slist_node_delete(SUFFIX) MUST__DEF3(slist_node, delete, SUFFIX)

must_slist(SUFFIX) *must_slist_malloc(SUFFIX)(void);
void must_slist_free(SUFFIX)(must_slist(SUFFIX) *slist);

must_slist(SUFFIX) *must_slist_new(SUFFIX)(void);
void must_slist_delete(SUFFIX)(must_slist(SUFFIX) **slist);

must_slist_node(SUFFIX) *must_slist_node_malloc(SUFFIX)(void);
void must_slist_node_free(SUFFIX)(must_slist_node(SUFFIX) *node);

must_slist_node(SUFFIX) *must_slist_node_new(SUFFIX)(TYPE data);
void must_slist_node_delete(SUFFIX)(must_slist_node(SUFFIX) **node);

#ifdef __cplusplus
}
#endif

#endif
