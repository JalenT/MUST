#ifdef TYPE

#ifndef TYPE
#define TYPE TYPE
#endif

#include <assert.h>
#include <stdlib.h>

#include "slist.h"

#ifdef __cplusplus
extern "C" {
#endif

/* -- Allocating & deallocating memory for types -- */
void must_slist_create(SUFFIX)(must_slist(SUFFIX) **slist)
{
	*slist = calloc(1, sizeof(must_slist(SUFFIX)));
}

void must_slist_destroy(SUFFIX)(must_slist(SUFFIX) **slist)
{
	if (slist == NULL) return;
	free(*slist);
	*slist = NULL;
}

void must_slist_new(SUFFIX)(must_slist(SUFFIX) **slist)
{
	must_slist_create(SUFFIX)(slist);
}

void must_slist_delete(SUFFIX)(must_slist(SUFFIX) **slist)
{
	if (slist == NULL && *slist == NULL) return;

	if ((*slist)->head != NULL) {
		must_slist_node(SUFFIX) *head = (*slist)->head;
		must_slist_node(SUFFIX) *to_delete;
		while (head->next != NULL) {
			to_delete  = head->next;
			head->next = to_delete->next;
			must_slist_node_destroy(SUFFIX)(&to_delete);
		}
		must_slist_node_destroy(SUFFIX)(&head);
	}

	must_slist_destroy(SUFFIX)(slist);
}

void must_slist_node_create(SUFFIX)(must_slist_node(SUFFIX) **node)
{
	*node = calloc(1, sizeof(must_slist_node(SUFFIX)));
}

void must_slist_node_destroy(SUFFIX)(must_slist_node(SUFFIX) **node)
{
	free(*node);
	*node = NULL;
}

void must_slist_node_new(SUFFIX)(must_slist_node(SUFFIX) **node, TYPE data)
{
	*node	      = calloc(1, sizeof(must_slist_node(SUFFIX)));
	(*node)->data = data;
}

void must_slist_node_delete(SUFFIX)(must_slist_node(SUFFIX) **node)
{
	must_slist_node_destroy(SUFFIX)(node);
}

/* -- Finding & getting nodes from singly linked lists -- */
must_slist_node(SUFFIX) *must_slist_get_node(SUFFIX)(must_slist(SUFFIX) *slist,
						     size_t index)
{
	assert(slist != NULL);
	assert(index < slist->length);

	must_slist_node(SUFFIX) *node = slist->head;
	while (index > 0 && node != NULL) {
		node = node->next;
		--index;
	}
	return node;
}

must_slist_node(SUFFIX) *must_slist_find_node(SUFFIX)(must_slist(SUFFIX) *slist,
						      TYPE data)
{
	assert(slist != NULL);

	must_slist_node(SUFFIX) *node = slist->head;
	while (node->data != data || node != NULL) {
		node = node->next;
	}
	return node;
}

/* -- Inserting nodes into the singly linked list -- */
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
				  must_slist_node(SUFFIX) *new_node)
{
	assert(slist != NULL);
	assert(node_before != NULL);
	assert(new_node != NULL);

	new_node->next	  = node_before->next;
	node_before->next = new_node;
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
