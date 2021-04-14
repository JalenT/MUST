#ifndef MUST__SLIST_MEM_C
#define MUST__SLIST_MEM_C

#include <stdlib.h> /* malloc */
#include <stddef.h>

#include "slist-types.h"
#include "slist-mem.h"

#ifdef __cplusplus
extern "C" {
#endif

/*
 * Functions for allocation & deallocation:
 *
 * new/delete
 * malloc/free
 */

must_slist(SUFFIX) *must_slist_malloc(SUFFIX)(void)
{
	return malloc(sizeof(must_slist(SUFFIX)));
}

void must_slist_free(SUFFIX)(must_slist(SUFFIX) *slist)
{
	free(slist);
}

must_slist(SUFFIX) *must_slist_new(SUFFIX)(void)
{
	/* Zero initialization is usually all zeroes */
	return calloc(sizeof(must_slist(SUFFIX)));
}

void must_slist_delete(SUFFIX)(must_slist(SUFFIX) **slist_double_ptr)
{
	if (slist_double_ptr == NULL) return;

	must_slist(SUFFIX) *slist = *slist_double_ptr;
	must_slist_node(SUFFIX) *to_delete;
	while (slist->head != NULL) {
		to_delete = slist->head;
		slist->head = to_delete->next;
		must_slist_node_free(SUFFIX)(to_delete);
	}

	free(*slist_double_ptr);
	*slist_double_ptr = NULL;
}

must_slist_node(SUFFIX) *must_slist_node_malloc(SUFFIX)(void)
{
	return malloc(sizeof(must_slist_node(SUFFIX)));
}

void must_slist_node_free(SUFFIX)(must_slist_node(SUFFIX) *node)
{
	free(node);
}

must_slist_node(SUFFIX) *must_slist_node_new(SUFFIX)(TYPE data)
{
	must_slist_node(SUFFIX) *node = must_slist_node_malloc(SUFFIX)();
	node->data = data;
	node->next = NULL;
	return node;
}

void must_slist_node_delete(SUFFIX)(must_slist_node(SUFFIX) **node)
{
	if (node == NULL) return;

	free(*node);
	*node = NULL;
}

#ifdef __cplusplus
}
#endif

#endif
