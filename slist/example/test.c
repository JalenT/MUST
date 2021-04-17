#include <assert.h>
#include <stdio.h>

#include <stdio.h>
#include <stdlib.h>

#include "slist-num.h"

int main(void)
{
	puts("\n** Allocating memory for the slist. **");
	must_slist_num *slist;
	must_slist_new(num)(&slist);
	printf("slist = %p\n", slist);
	assert(slist != NULL);

	puts("\n** Allocating memeory for the nodes. **");
	must_slist_node(num) *n1;
	must_slist_node(num) *n2;
	must_slist_node(num) *n3;
	must_slist_node(num) *n4;
	must_slist_node(num) *n5;

	must_slist_node_new_num(&n1, 1);
	must_slist_node_new_num(&n2, 2);
	must_slist_node_new_num(&n3, 3);
	must_slist_node_new_num(&n4, 4);
	must_slist_node_new_num(&n5, 5);

	printf("n1 = %p\n", n1);
	printf("n2 = %p\n", n2);
	printf("n3 = %p\n", n3);
	printf("n4 = %p\n", n4);
	printf("n5 = %p\n", n5);

	assert(n1 != NULL);
	assert(n2 != NULL);
	assert(n3 != NULL);
	assert(n4 != NULL);
	assert(n5 != NULL);

	puts("\n** Adding nodes into the slist. **");

	must_slist_put(num)(slist, 0, n1);
	must_slist_put(num)(slist, 1, n2);
	must_slist_put(num)(slist, 2, n3);
	must_slist_put(num)(slist, 3, n4);
	must_slist_put(num)(slist, 4, n5);

	printf("slist->length = %llu\n", slist->length);
	assert(slist->length == 5);

	puts("\n** Getting the 3rd node in the list. **");

	must_slist_node_num *my_node = must_slist_get_node_num(slist, 2);
	printf("my_node->data = %d\n", my_node->data);
	assert(my_node == n3);

	puts("\n** Removing the tail from the list **");

	my_node			       = my_node->next;
	must_slist_node_num *to_delete = my_node->next;
	my_node->next		       = NULL;
	must_slist_node_delete(num)(&to_delete);

	printf("to_delete = %p\n", to_delete);
	assert(to_delete == NULL);

	printf("my_node->next = %p\n", my_node->next);
	assert(my_node->next == NULL);

	puts("\n** Freeing the entire list **");
	must_slist_delete_(num)(&slist);

	printf("slist = %p\n", slist);
	assert(slist == NULL);

	puts("\n** It worked with no problems!!! **");
}
