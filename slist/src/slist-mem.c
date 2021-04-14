#ifndef MUST__SLIST_MEM_C
#define MUST__SLIST_MEM_C

#include <assert.h>
#include <stddef.h>
#include <stdlib.h> /* malloc */

#include "slist-mem.h"
#include "slist-types.h"

#ifdef __cplusplus
extern "C" {
#endif

/*
 * create()/destroy()
 * new()/delete()
 */

void must_slist_create(SUFFIX)(must_slist(SUFFIX) *slist)
{
	slist = malloc(sizeof(must_slist(SUFFIX)));
	slist->head = NULL;
	slist->length = 0;
}

void must_slist_destroy(SUFFIX)(must_slist(SUFFIX) **slist)
{
	assert(slist != NULL);
	free(*slist);
	*slist = NULL;
}

void must_slist_new(SUFFIX)(must_slist(SUFFIX) *slist)
{
	must_slist_create(SUFFIX)(slist);
}

void must_slist_delete(SUFFIX)(must_slist(SUFFIX) **slist)
{
	assert(slist != NULL);

	if (*slist != NULL && (*slist)->head != NULL) {
		must_slist(SUFFIX) *head = (*slist)->head;
		must_slist(SUFFIX) *to_delete;
		while (head->next != NULL) {
			to_delete = head->next;
			head->next = to_delete->next;
			must_slist_node_destroy(SUFFIX)(&to_delete);
		}
		must_slist_node_destroy(&head);
	}

	must_slist_destroy(slist);
}

void must_slist_node_create(SUFFIX)(must_slist_node(SUFFIX) *node)
{
	node = malloc(sizeof(must_slist_node(SUFFIX)));
	node->data = 0; /* Sets data to it's zero-value */
	node->next = NULL;
}

void must_slist_node_destroy(SUFFIX)(must_slist_node(SUFFIX) **node)
{
	free(*node);
	*node = NULL;
}

void must_slist_node_new(SUFFIX)(must_slist_node(SUFFIX) *node, TYPE data)
{
	node = malloc(sizeof(must_slist_node(SUFFIX)));
	node->data = data;
	node->next = NULL;
}

void must_slist_node_delete(SUFFIX)(must_slist_node(SUFFIX) **node)
{
	must_slist_node_destroy(*node);
	*node = NULL;
}

#ifdef __cplusplus
}
#endif

#endif
