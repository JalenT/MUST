#ifdef TYPE

#ifndef ID
#define ID TYPE
#endif

#include "slist.h"

#include <assert.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

/* -- Allocating & deallocating memory for types -- */
void must_slist_create(ID)(must_slist(ID) **slist)
{
	*slist = calloc(1, sizeof(must_slist(ID)));
}

void must_slist_destroy(ID)(must_slist(ID) **slist)
{
	if (slist == NULL)
		return;
	free(*slist);
	*slist = NULL;
}

void must_slist_new(ID)(must_slist(ID) **slist)
{
	must_slist_create(ID)(slist);
}

void must_slist_delete(ID)(must_slist(ID) **slist)
{
	if (slist == NULL && *slist == NULL)
		return;

	must_slist_node(ID) *to_delete;
	while ((*slist)->head != NULL) {
		to_delete = must_slist_remove_front(ID)(*slist);
		must_slist_node_destroy(ID)(&to_delete);
	}

	must_slist_destroy(ID)(slist);
}

void must_slist_node_create(ID)(must_slist_node(ID) **node)
{
	*node = calloc(1, sizeof(must_slist_node(ID)));
}

void must_slist_node_destroy(ID)(must_slist_node(ID) **node)
{
	free(*node);
	*node = NULL;
}

void must_slist_node_new(ID)(must_slist_node(ID) **node, TYPE data)
{
	*node = calloc(1, sizeof(must_slist_node(ID)));
	(*node)->data = data;
}

void must_slist_node_delete(ID)(must_slist_node(ID) **node)
{
	must_slist_node_destroy(ID)(node);
}

/* -- Finding & getting nodes from singly linked lists -- */
must_slist_node(ID) *must_slist_get_node(ID)(must_slist(ID) *slist,
					     size_t index)
{
	assert(slist != NULL);
	assert(index < slist->length);

	must_slist_node(ID) *node = slist->head;
	while (index > 0 && node != NULL) {
		node = node->next;
		--index;
	}
	return node;
}

must_slist_node(ID) *must_slist_find_node(ID)(must_slist(ID) *slist, TYPE data)
{
	assert(slist != NULL);

	must_slist_node(ID) *node = slist->head;
	while (node->data != data || node != NULL)
		node = node->next;

	return node;
}

/* -- Inserting nodes into the singly linked list -- */
void must_slist_add_node_front(ID)(must_slist(ID) *slist,
				   must_slist_node(ID) *node)
{
	assert(slist != NULL);
	assert(node != NULL);

	node->next = slist->head;
	slist->head = node;
	++slist->length;
}

void must_slist_add_node_after(ID)(must_slist(ID) *slist,
				   must_slist_node(ID) *node_before,
				   must_slist_node(ID) *new_node)
{
	assert(slist != NULL);
	assert(node_before != NULL);
	assert(new_node != NULL);

	new_node->next = node_before->next;
	node_before->next = new_node;
	++slist->length;
}

void must_slist_add_node(ID)(must_slist(ID) *slist, size_t index,
			     must_slist_node(ID) *node)
{
	assert(slist != NULL);
	assert(index <= slist->length);
	assert(node != NULL);

	if (index == 0)
		must_slist_add_node_front(ID)(slist, node);

	must_slist_node(ID) *prev_node;
	prev_node = must_slist_get_node(ID)(slist, index - 1);
	must_slist_add_node_after(ID)(slist, prev_node, node);
}

/* -- Removing nodes from the singly linked list -- */
must_slist_node(ID) *must_slist_remove_front(ID)(must_slist(ID) *slist)
{
	assert(slist != NULL);

	if (slist->head == NULL)
		return NULL;

	must_slist_node(ID) *old_head = slist->head;
	slist->head = old_head->next;
	--slist->length;
	return old_head;
}

must_slist_node(ID) *must_slist_remove_after(ID)(must_slist(ID) *slist,
						 must_slist_node(ID) *node)
{
	assert(slist != NULL);
	assert(node != NULL);

	must_slist_node(ID) *old_node = node->next;
	node->next = old_node->next;
	--slist->length;
	return old_node;
}

must_slist_node(ID) *must_slist_remove(ID)(must_slist(ID) *slist, size_t index)
{
	assert(slist != NULL);
	assert(index <= slist->length);

	if (index == 0)
		return must_slist_remove_front(ID)(slist);

	must_slist_node(ID) *prev_node;
	prev_node = must_slist_get_node(ID)(slist, index - 1);
	return must_slist_remove_after(ID)(slist, prev_node);
}

#ifdef __cplusplus
}
#endif

#endif
