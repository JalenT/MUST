#ifdef TYPE

#ifndef SUFFIX
#define SUFFIX TYPE
#endif

#ifdef __cplusplus
extern "C" {
#endif

#include <stdlib.h> /* malloc & free */

#include "slist.h"

/* Allocating memory for types */
must_slist(SUFFIX) *must_slist_new(SUFFIX)(void)
{
	must_slist(SUFFIX) *slist = malloc(sizeof(must_slist(SUFFIX)));
	slist->head		  = NULL;
	slist->length		  = 0;
	return slist;
}

must_slist_node(SUFFIX) *must_slist_node_new(SUFFIX)(TYPE data)
{
	must_slist_node(SUFFIX) *node = malloc(sizeof(must_slist_node(SUFFIX)));
	node->data		      = data;
	node->next		      = NULL;
	return node;
}

/* Deallocating memory for types */
void must_slist_free(SUFFIX)(must_slist(SUFFIX) *slist)
{
	free(slist);
}

void must_slist_node_free(SUFFIX)(must_slist_node(SUFFIX) *node)
{
	free(node);
}

#ifdef __cplusplus
}
#endif

#endif
