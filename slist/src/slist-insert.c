#ifndef MUST__SLIST_INSERT_C
#define MUST__SLIST_INSERT_C

#include <assert.h> /* assert() */
#include <stddef.h> /* size_t */

#include "slist-find.h"
#include "slist-insert.h"
#include "slist-types.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Inserting nodes into the singly linked list */
void must_slist_put_front(SUFFIX)(must_slist(SUFFIX) *slist,
				  must_slist_node(SUFFIX) *node)
{
	assert(slist != NULL);
	assert(node != NULL);

	node->next  = slist->head;
	slist->head = node;
	++slist->length;
}

void must_slist_put_after(SUFFIX)(must_slist(SUFFIX) *slist,
				  must_slist_node(SUFFIX) *node_before,
				  must_slist_node(SUFFIX) *node_after)
{
	assert(slist != NULL);
	assert(node_before != NULL);
	assert(node_after != NULL);

	node_after->next  = node_before->next;
	node_before->next = node_after;
	++slist->length;
}

void must_slist_put(SUFFIX)(must_slist(SUFFIX) *slist, size_t index,
			    must_slist_node(SUFFIX) *node)
{
	assert(slist != NULL);
	assert(index <= slist->length);
	assert(node != NULL);

	if (index == 0) {
		must_slist_put_front(SUFFIX)(slist, node);
	} else {
		must_slist_node(SUFFIX) *prev_node;
		prev_node = must_slist_get_node(SUFFIX)(slist, (index - 1));
		must_slist_put_after(SUFFIX)(slist, prev_node, node);
	}
}

#ifdef __cplusplus
}
#endif

#endif
