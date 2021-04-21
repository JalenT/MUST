#ifdef TYPE

#ifndef ID
#define ID TYPE
#endif

#include <stddef.h>

#include "def.h"

#ifdef __cplusplus
extern "C" {
#endif

/* -- Defining all of the types -- */

#define must_slist_node(ID) MUST__DEF2(slist_node, ID)
typedef struct must_slist_node(ID)
{
	TYPE data;
	struct must_slist_node(ID) *next;
}
must_slist_node(ID);

#define must_slist(ID) MUST__DEF2(slist, ID)
typedef struct must_slist(ID)
{
	struct must_slist_node(ID) *head;
	size_t length;
}
must_slist(ID);

/* -- Allocating & deallocating memory for types -- */

/*
 * INFO: It sets the head pointer to NULL & length to 0.
 */
#define must_slist_create(ID) MUST__DEF3(slist, create, ID)
void must_slist_create(ID)(must_slist(ID) **slist);

/*
 * WARNING: It will produce memory leaks if the head pointer is not NULL.
 * INFO: Use must_slist_delete() to not produce memory leaks.
 * INFO: This function only free the pointer and sets it to NULL.
 */
#define must_slist_destroy(ID) MUST__DEF3(slist, destroy, ID)
void must_slist_destroy(ID)(must_slist(ID) **slist);

/*
 * INFO: Does the same as must_slist_create().
 * INFO: Created this to keep interface similar to other types.
 */
#define must_slist_new(ID) MUST__DEF3(slist, new, ID)
void must_slist_new(ID)(must_slist(ID) **slist);

/*
 * INFO: This function will free all the nodes in the singly linked list, if
 * any, before freeing the singly linked list & setting it to NULL.
 * INFO: It will not produce memeory leaks.
 */
#define must_slist_delete(ID) MUST__DEF3(slist, delete, ID)
void must_slist_delete(ID)(must_slist(ID) **slist);

/*
 * INFO: It sets data to 0 & the next pointer to NULL.
 * INFO: Use must_slist_node_create() if you want to initialize the node to a
 * different value.
 */
#define must_slist_node_create(ID) MUST__DEF3(slist_node, create, ID)
void must_slist_node_create(ID)(must_slist_node(ID) **node);

/*
 * WARNING: This function only free the pointer and sets it to NULL.
 * INFO: The pointer is set to NULL before returning.
 */
#define must_slist_node_destroy(ID) MUST__DEF3(slist_node, destroy, ID)
void must_slist_node_destroy(ID)(must_slist_node(ID) **node);

/*
 * INFO: Use must_slist_node_create() if you want to initialize the node to the
 * zero value.
 */
#define must_slist_node_new(ID) MUST__DEF3(slist_node, new, ID)
void must_slist_node_new(ID)(must_slist_node(ID) **node, TYPE data);

/*
 * WARNING: This function only free the pointer and sets it to NULL.
 * INFO: Does the same thing as must_slist_node_destroy().
 * INFO: Made to keep type interface similar to other types.
 */
#define must_slist_node_delete(ID) MUST__DEF3(slist_node, delete, ID)
void must_slist_node_delete(ID)(must_slist_node(ID) **node);

/* -- Finding & getting nodes from singly linked lists -- */

/*
 * INFO: This function gets the node at the zero-based index provided.
 */
#define must_slist_get_node(ID) MUST__DEF3(slist, get_node, ID)
must_slist_node(ID) *must_slist_get_node(ID)(must_slist(ID) *slist,
					     size_t index);

/*
 * INFO: Returns the first instance of that data.
 */
#define must_slist_find_node(ID) MUST__DEF3(slist, find_node, ID)
must_slist_node(ID) *must_slist_find_node(ID)(must_slist(ID) *slist, TYPE data);

/* -- Inserting nodes into the singly linked list -- */

/*
 * INFO: The function puts the node at the head of the singly linked list.
 */
#define must_slist_add_node_front(ID) MUST__DEF3(slist, add_node_front, ID)
void must_slist_add_node_front(ID)(must_slist(ID) *slist,
				   must_slist_node(ID) *node);

/*
 * INFO: The function puts the new node after the other node given.
 */
#define must_slist_add_node_after(ID) MUST__DEF3(slist, add_node_after, ID)
void must_slist_add_node_after(ID)(must_slist(ID) *slist,
				   must_slist_node(ID) *node_before,
				   must_slist_node(ID) *new_node);

/*
 * INFO: The function puts the node at the given zero-based index.
 */
#define must_slist_add_node(ID) MUST__DEF3(slist, add_node, ID)
void must_slist_add_node(ID)(must_slist(ID) *slist, size_t index,
			     must_slist_node(ID) *node);

/* -- Removing nodes from the singly linked list -- */

/*
 * INFO: The function removes the head from the list.
 * INFO: The function returns the removed node.
 */
#define must_slist_remove_front(ID) MUST__DEF3(slist, remove_front, ID)
must_slist_node(ID) *must_slist_remove_front(ID)(must_slist(ID) *slist);

/*
 * INFO: The function removes the node after the given one in the list.
 * INFO: The function returns the removed node.
 */
#define must_slist_remove_after(ID) MUST__DEF3(slist, remove_after, ID)
must_slist_node(ID) *must_slist_remove_after(ID)(must_slist(ID) *slist,
						 must_slist_node(ID) *node);

/*
 * INFO: The function removes the node at the zero-based index.
 * INFO: The function returns the removed node.
 */
#define must_slist_remove(ID) MUST__DEF3(slist, remove, ID)
must_slist_node(ID) *must_slist_remove(ID)(must_slist(ID) *slist, size_t index);

#ifdef __cplusplus
}
#endif

#endif
