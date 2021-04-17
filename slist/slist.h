#ifdef TYPE

#ifndef SUFFIX
#define SUFFIX TYPE
#endif

#include <stddef.h>

#include "def.h"

#ifdef __cplusplus
extern "C" {
#endif

/* -- Defining all of the types -- */

#define must_slist_node(SUFFIX) MUST__DEF2(slist_node, SUFFIX)
typedef struct must_slist_node(SUFFIX)
{
	TYPE data;
	struct must_slist_node(SUFFIX) *next;
}
must_slist_node(SUFFIX);

#define must_slist(SUFFIX) MUST__DEF2(slist, SUFFIX)
typedef struct must_slist(SUFFIX)
{
	struct must_slist_node(SUFFIX) *head;
	size_t length;
}
must_slist(SUFFIX);

/* -- Allocating & deallocating memory for types -- */

/*
 * INFO: It sets the head pointer to NULL & length to 0.
 */
#define must_slist_create(SUFFIX) MUST__DEF3(slist, create, SUFFIX)
void must_slist_create(SUFFIX)(must_slist(SUFFIX) **slist);

/*
 * WARNING: It will produce memory leaks if the head pointer is not NULL.
 * INFO: Use must_slist_delete() to not produce memory leaks.
 * INFO: This function only free the pointer and sets it to NULL.
 */
#define must_slist_destroy(SUFFIX) MUST__DEF3(slist, destroy, SUFFIX)
void must_slist_destroy(SUFFIX)(must_slist(SUFFIX) **slist);

/*
 * INFO: Does the same as must_slist_create().
 * INFO: Created this to keep interface similar to other types.
 */
#define must_slist_new(SUFFIX) MUST__DEF3(slist, new, SUFFIX)
void must_slist_new(SUFFIX)(must_slist(SUFFIX) **slist);

/*
 * INFO: This function will free all the nodes in the singly linked list, if
 * any, before freeing the singly linked list & setting it to NULL.
 * INFO: It will not produce memeory leaks.
 */
#define must_slist_delete(SUFFIX) MUST__DEF3(slist, delete, SUFFIX)
void must_slist_delete(SUFFIX)(must_slist(SUFFIX) **slist);

/*
 * INFO: It sets data to 0 & the next pointer to NULL.
 * INFO: Use must_slist_node_create() if you want to initialize the node to a
 * different value.
 */
#define must_slist_node_create(SUFFIX) MUST__DEF3(slist_node, create, SUFFIX)
void must_slist_node_create(SUFFIX)(must_slist_node(SUFFIX) **node);

/*
 * WARNING: This function only free the pointer and sets it to NULL.
 * INFO: The pointer is set to NULL before returning.
 */
#define must_slist_node_destroy(SUFFIX) MUST__DEF3(slist_node, destroy, SUFFIX)
void must_slist_node_destroy(SUFFIX)(must_slist_node(SUFFIX) **node);

/*
 * INFO: Use must_slist_node_create() if you want to initialize the node to the
 * zero value.
 */
#define must_slist_node_new(SUFFIX) MUST__DEF3(slist_node, new, SUFFIX)
void must_slist_node_new(SUFFIX)(must_slist_node(SUFFIX) **node, TYPE data);

/*
 * WARNING: This function only free the pointer and sets it to NULL.
 * INFO: Does the same thing as must_slist_node_destroy().
 * INFO: Made to keep type interface similar to other types.
 */
#define must_slist_node_delete(SUFFIX) MUST__DEF3(slist_node, delete, SUFFIX)
void must_slist_node_delete(SUFFIX)(must_slist_node(SUFFIX) **node);

/* -- Finding & getting nodes from singly linked lists -- */

/*
 * INFO: This function gets the node at the zero-based index provided.
 */
#define must_slist_get_node(SUFFIX) MUST__DEF3(slist, get_node, SUFFIX)
must_slist_node(SUFFIX) *must_slist_get_node(SUFFIX)(must_slist(SUFFIX) *slist,
						     size_t index);

/*
 * INFO: Returns the first instance of that data.
 */
#define must_slist_find_node(SUFFIX) MUST__DEF3(slist, find_node, SUFFIX)
must_slist_node(SUFFIX) *must_slist_find_node(SUFFIX)(must_slist(SUFFIX) *slist,
						      TYPE data);

/* -- Inserting nodes into the singly linked list -- */

/*
 * INFO: The function puts the node at the head of the singly linked list.
 */
#define must_slist_put_front(SUFFIX) MUST__DEF3(slist, put_front, SUFFIX)
void must_slist_put_front(SUFFIX)(must_slist(SUFFIX) *slist,
				  must_slist_node(SUFFIX) *node);

/*
 * INFO: The function puts the new node after the other node given.
 */
#define must_slist_put_after(SUFFIX) MUST__DEF3(slist, put_after, SUFFIX)
void must_slist_put_after(SUFFIX)(must_slist(SUFFIX) *slist,
				  must_slist_node(SUFFIX) *node_before,
				  must_slist_node(SUFFIX) *new_node);

/*
 * INFO: The function puts the node at the given zero-based index.
 */
#define must_slist_put(SUFFIX) MUST__DEF3(slist, put, SUFFIX)
void must_slist_put(SUFFIX)(must_slist(SUFFIX) *slist, size_t index,
			    must_slist_node(SUFFIX) *node);

#ifdef __cplusplus
}
#endif

#endif
