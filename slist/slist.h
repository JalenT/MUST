#ifdef TYPE

#ifndef SUFFIX
#define SUFFIX TYPE
#endif

#ifdef __cplusplus
extern "C" {
#endif

#include <stddef.h> /* size_t */

#include "def.h" /* MUST__DEF2 & MUST__DEF3 */

/* Declaring types */
#define must_slist(SUFFIX)	MUST__DEF2(slist, SUFFIX)
#define must_slist_node(SUFFIX) MUST__DEF2(slist_node, SUFFIX)

typedef struct must_slist_node(SUFFIX) must_slist_node(SUFFIX);
typedef struct must_slist(SUFFIX) must_slist(SUFFIX);

/* Defining Types */
struct must_slist(SUFFIX)
{
	struct must_slist_node(SUFFIX) *head;
	size_t length;
};

struct must_slist_node(SUFFIX)
{
	TYPE data;
	struct must_slist_node(SUFFIX) *next;
};

/* Allocating memory for types */
#define must_slist_new(SUFFIX)	    MUST__DEF3(slist, new, SUFFIX)
#define must_slist_node_new(SUFFIX) MUST__DEF3(slist_node, new, SUFFIX)

must_slist(SUFFIX) *must_slist_new(SUFFIX)(void);
must_slist_node(SUFFIX) *must_slist_node_new(SUFFIX)(TYPE data);

/* Deallocating memory for types */
#define must_slist_free(SUFFIX)	     MUST__DEF3(slist, free, SUFFIX)
#define must_slist_node_free(SUFFIX) MUST__DEF3(slist_node, free, SUFFIX)

void must_slist_free(SUFFIX)(must_slist(SUFFIX) *slist);
void must_slist_node_free(SUFFIX)(must_slist_node(SUFFIX) *node);

#ifdef __cplusplus
}
#endif

#endif
