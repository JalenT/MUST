#ifndef MUST__SLIST_FIND_C
#define MUST__SLIST_FIND_C

#include <assert.h> /* assert() */
#include <stddef.h> /* size_t & NULL */

#include "slist-find.h"
#include "slist-types.h"

#ifdef __cplusplus
extern "C" {
#endif

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
	while (node->data != data || node != NULL) node = node->next;
	return node;
}

#ifdef __cplusplus
}
#endif

#endif
