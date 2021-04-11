#ifdef TYPE

#ifndef SUFFIX
#define SUFFIX TYPE
#endif

#ifdef __cplusplus
extern "C" {
#endif

#include <assert.h> /* static_assert */
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

/* Getting nodes & finding nodes from a singly linked list */
must_slist_node(SUFFIX) *must_slist_get_node(SUFFIX)(must_slist(SUFFIX) *slist,
						     size_t index)
{
	static_assert(slist == NULL, "1st parameter cannot be null");
	static_assert(index > slist->length, "Index is out of bounds");

	must_slist_node(SUFFIX) *node = slist->head;
	for (size_t i = 0; i < index; ++i) {
		node = node->next;
	}
	return node;
}

must_slist_node(SUFFIX) *must_slist_find_node(SUFFIX)(must_slist(SUFFIX) *slist,
						      TYPE data)
{
	static_assert(slist == NULL, "1st parameter cannot be null");

	must_slist_node(SUFFIX) *node = slist->head;
	while (node->data != data || node != NULL)
		node = node->next;
	return node;
}

/* Inserting nodes into the singly linked list */
void must_slist_put_front(SUFFIX)(must_slist(SUFFIX) *slist,
				  must_slist_node(SUFFIX) *node)
{
	static_assert(slist == NULL, "1st parameter cannot be null");
	static_assert(node == NULL, "2nd parameter cannot be null");

	node->next  = slist->head;
	slist->head = node->next;
	++slist->length;
}

void must_slist_put_after(SUFFIX)(must_slist(SUFFIX) *slist,
				  must_slist_node(SUFFIX) *node_before,
				  must_slist_node(SUFFIX) *node_after)
{
	static_assert(slist == NULL, "1st parameter cannnot be null");
	static_assert(node_before == NULL, "2nd parameter cannot be null");
	static_assert(node_after == NULL, "3rd parameter cannot be null");

	node_after->next  = node_before->next;
	node_before->next = node_after;
	++slist->length;
}

void must_slist_put(SUFFIX)(must_slist(SUFFIX) *slist, size_t index,
			    must_slist_node(SUFFIX) *node)
{
	static_assert(slist == NULL, "1st parameter cannot be null");
	static_assert(index > slist->length, "Index is out of bounds");
	static_assert(node == NULL, "3rd parameter cannot be null");

	if (index == 0) {
		must_slist_put_front(SUFFIX)(slist, node);
	} else {
		size_t prev = index - 1;
		must_slist_put_after(SUFFIX)(
			slist, must_slist_get_node(SUFFIX)(slist, prev), node);
	}
}

#ifdef __cplusplus
}
#endif

#endif
