#include <assert.h>
#include <stdio.h>

#include <stdio.h>
#include <stdlib.h>

#include "slist-str.h"

int main(void)
{
	puts("\n** Allocating memory for the slist. **");
	must_slist(str) *slist = must_slist_new(str)();
	printf("slist = %p\n", slist);
	assert(slist != NULL);

	puts("\n** Allocating memeory for the nodes. **");
	must_slist_node(str) *n1 = must_slist_node_new(str)("a");
	must_slist_node(str) *n2 = must_slist_node_new(str)("b");
	must_slist_node(str) *n3 = must_slist_node_new(str)("c");
	must_slist_node(str) *n4 = must_slist_node_new(str)("d");
	must_slist_node(str) *n5 = must_slist_node_new(str)("e");

	printf("n1->data = %s\n", n1->data);
	printf("n2->data = %s\n", n2->data);
	printf("n3->data = %s\n", n3->data);
	printf("n4->data = %s\n", n4->data);
	printf("n5->data = %s\n", n5->data);

	assert(n1 != NULL);
	assert(n2 != NULL);
	assert(n3 != NULL);
	assert(n4 != NULL);
	assert(n5 != NULL);

	puts("\n** Adding nodes into the slist. **");

	must_slist_put(str)(slist, 0, n1);
	must_slist_put(str)(slist, 1, n2);
	must_slist_put(str)(slist, 2, n3);
	must_slist_put(str)(slist, 3, n4);
	must_slist_put(str)(slist, 4, n5);

	printf("slist->length = %llu\n", slist->length);
	assert(slist->length == 5);

	puts("\n** Getting the 3rd node in the list. **");

	must_slist_node(str) *my_node = must_slist_get_node(str)(slist, 2);
	printf("my_node->data = %s\n", my_node->data);
	assert(my_node == n3);

	puts("\n** Removing the tail from the list **");

	my_node = my_node->next;
	must_slist_node(str) *to_delete = my_node->next;
	my_node->next = NULL;
	must_slist_node_delete(str)(&to_delete);

	printf("to_delete = %p\n", to_delete);
	assert(to_delete == NULL);

	printf("my_node->next = %p\n", my_node->next);
	assert(my_node->next == NULL);

	puts("\n** Freeing the entire list **");
	must_slist_free(str)(slist);

	getchar();
}
